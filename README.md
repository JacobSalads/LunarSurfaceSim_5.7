# Lunar Surface Optical Navigation Simulator

## Requirements
- Unreal Engine 5.7+
- Git LFS installed

## Required Plugins (install via Fab/Marketplace)
- MaxQ Spaceflight Toolkit (free) — by SpartanTools
- TCP Socket Plugin (free) — by SpartanTools  
- Cesium for Unreal (free) — by Cesium

## Required SPICE Kernels
Download and place in Content/CustomBuilds/SPICE/kernals/Lunar/:
- de440s.bsp — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/
- naif0012.tls — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/lsk/
- pck00010.tpc — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/
- moon_pa_de440_200625.bpc — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/
- moon_080317.tf — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/fk/satellites/
- moon_assoc_me.tf — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/fk/satellites/
- moon_de440_250416.tf — https://naif.jpl.nasa.gov/pub/naif/generic_kernels/fk/satellites/

## Python Requirements
pip install numpy pillow spiceypy scipy osgeo pyvista

## Setup Steps
1. Clone the repository
2. Install UE5 5.7+
3. Install required plugins via Fab
4. Download SPICE kernels
5. Open LunarSurfaceSim.uproject
