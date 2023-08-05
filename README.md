# AmeenuddinVM
This is a library for Ameenuddin viscosity model written based on foam-extend-4.1.


## Mathematical Relationships
$$ {\nu} = \nu_{\infty} + \left({\nu_0 - \nu_{\infty}} \right) { {1 + ln \left({ 1 + \lambda \dot{\gamma} } \right) } \over { 1 + \lambda \dot{\gamma} } }$$

$$ {\nu_0} = {0.0736 \over \rho} \left({ a_1 + a_2 Hct + a_3 Hct^2 }\right) $$

$$ {\nu_{\infty}} = {0.005\over \rho} \left({ b_1 + b_2 Hct + b_3 Hct^2 }\right) $$

$$ \lambda = 14.81 \left({ c_1 + c_2 Hct + c_3 Hct^2 }\right) $$

$\nu$, $\gamma$, and $Hct$ are kinematic viscosity, strain rate, and hematocrit, respectively.


## Installation
It is working on foam-extend-4.1
```bash
git clone https://github.com/EhsanGLB/AmeenuddinVM.git
cd AmeenuddinVM/AmeenuddinVM
wmake libso
cd ../case
```


## Getting Started
```bash
blockMesh
nonNewtonianIcoFoam
```


## Activation
Add "libAmeenuddinVM.so" to case/system/controlDict


## References
* [Golab, Ehsan, Behzad Vahedi, Ankur Jain, Robert A. Taylor, and Kambiz Vafai. "Laminar forced convection in a tube with a nano-encapsulated phase change materials: Minimizing exergy losses and maximizing the heat transfer rate." Journal of Energy Storage 65 (2023): 107233.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X23006308)
* [Vahedi, Behzad, Ehsan Golab, Arsalan Nasiri Sadr, and Kambiz Vafai. "Thermal, thermodynamic and exergoeconomic investigation of a parabolic trough collector utilizing nanofluids." Applied Thermal Engineering 206 (2022): 118117.](https://www.sciencedirect.com/science/article/abs/pii/S1359431122000813)
* [Golab, Ehsan, Sahar Goudarzi, Hamed Kazemi-Varnamkhasti, Hossein Amigh, Ferial Ghaemi, Dumitru Baleanu, and Arash Karimipour. "Investigation of the effect of adding nano-encapsulated phase change material to water in natural convection inside a rectangular cavity." Journal of Energy Storage 40 (2021): 102699.](https://www.sciencedirect.com/science/article/abs/pii/S2352152X21004357)
* [Abbasi, Mohammad, Amin Nadimian Esfahani, Ehsan Golab, Omid Golestanian, Nima Ashouri, S. Mohammad Sajadi, Ferial Ghaemi, Dumitru Baleanu, and A. Karimipour. "Effects of Brownian motions and thermophoresis diffusions on the hematocrit and LDL concentration/diameter of pulsatile non-Newtonian blood in abdominal aortic aneurysm." Journal of Non-Newtonian Fluid Mechanics 294 (2021): 104576.](https://www.sciencedirect.com/science/article/abs/pii/S0377025721000859)
* [Jafarzadeh, Sina, Arsalan Nasiri Sadr, Ehsan Kaffash, Sahar Goudarzi, Ehsan Golab, and Arash Karimipour. "The effect of hematocrit and nanoparticles diameter on hemodynamic parameters and drug delivery in abdominal aortic aneurysm with consideration of blood pulsatile flow." Computer Methods and Programs in Biomedicine 195 (2020): 105545.](https://www.sciencedirect.com/science/article/abs/pii/S0169260720307914)
* [Goudarzi, Sahar, Masih Shekaramiz, Alireza Omidvar, Ehsan Golab, Arash Karimipour, and Aliakbar Karimipour. "Nanoparticles migration due to thermophoresis and Brownian motion and its impact on Ag-MgO/Water hybrid nanofluid natural convection." Powder Technology 375 (2020): 493-503.](https://www.sciencedirect.com/science/article/abs/pii/S0032591020307397)
* [Motlagh, Saber Yekani, Ehsan Golab, and Arsalan Nasiri Sadr. "Two-phase modeling of the free convection of nanofluid inside the inclined porous semi-annulus enclosure." International Journal of Mechanical Sciences 164 (2019): 105183.](https://www.sciencedirect.com/science/article/abs/pii/S0020740319315279)
