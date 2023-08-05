/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.1
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "AmeenuddinVM.H"
#include "addToRunTimeSelectionTable.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace viscosityModels
{
    defineTypeNameAndDebug(AmeenuddinVM, 0);

    addToRunTimeSelectionTable
    (
        viscosityModel,
        AmeenuddinVM,
        dictionary
    );
}
}


// * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::viscosityModels::AmeenuddinVM::calcNu() const
{
    dimensionedScalar nu0_ = 0.0736*(a1_ + a2_*hct_ + a3_*pow(hct_, 2))/rho_;
    dimensionedScalar nuInf_ = 0.005*(b1_ + b2_*hct_ + b3_*pow(hct_, 2))/rho_;
    dimensionedScalar lambda_ = 14.81*(c1_*hct_ + c2_*pow(hct_, 2));

    return nuInf_ + (nu0_ - nuInf_) * ((1+log(1+lambda_*strainRate()))/(1+lambda_*strainRate()));
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::viscosityModels::AmeenuddinVM::AmeenuddinVM
(
    const word& name,
    const dictionary& viscosityProperties,
    const volVectorField& U,
    const surfaceScalarField& phi
)
:
    viscosityModel(name, viscosityProperties, U, phi),
    AmeenuddinVMCoeffs_(viscosityProperties.subDict(typeName + "Coeffs")),
    a1_(AmeenuddinVMCoeffs_.lookup("a1")),
    a2_(AmeenuddinVMCoeffs_.lookup("a2")),
    a3_(AmeenuddinVMCoeffs_.lookup("a3")),
    b1_(AmeenuddinVMCoeffs_.lookup("b1")),
    b2_(AmeenuddinVMCoeffs_.lookup("b2")),
    b3_(AmeenuddinVMCoeffs_.lookup("b3")),
    c1_(AmeenuddinVMCoeffs_.lookup("c1")),
    c2_(AmeenuddinVMCoeffs_.lookup("c2")),
    rho_(AmeenuddinVMCoeffs_.lookup("rho")),
    hct_(AmeenuddinVMCoeffs_.lookup("hct")),
    nu_
    (
        IOobject
        (
            name,
            U_.time().timeName(),
            U_.db(),
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        calcNu()
    )
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

bool Foam::viscosityModels::AmeenuddinVM::read
(
    const dictionary& viscosityProperties
)
{
    viscosityModel::read(viscosityProperties);

    AmeenuddinVMCoeffs_ = viscosityProperties.subDict(typeName + "Coeffs");

    AmeenuddinVMCoeffs_.lookup("a1") >> a1_;
    AmeenuddinVMCoeffs_.lookup("a2") >> a2_;
    AmeenuddinVMCoeffs_.lookup("a3") >> a3_;
    AmeenuddinVMCoeffs_.lookup("b1") >> b1_;
    AmeenuddinVMCoeffs_.lookup("b2") >> b2_;
    AmeenuddinVMCoeffs_.lookup("b3") >> b3_;
    AmeenuddinVMCoeffs_.lookup("c1") >> c1_;
    AmeenuddinVMCoeffs_.lookup("c2") >> c2_;
    AmeenuddinVMCoeffs_.lookup("rho") >> rho_;
    AmeenuddinVMCoeffs_.lookup("hct") >> hct_;

    return true;
}


// ************************************************************************* //
