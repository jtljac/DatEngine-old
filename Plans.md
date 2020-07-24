# Rendering
## Technique
### Hybrid Tiled Deferred rendering
#### Tiled
Break the view frustrum up into cells in XYZ
 * Use tiles to discover what light affects what models
    * If cell is empty, don't check for lights
    * Add all lights to frustrum, store with cell index and only calculate lights in cell
 * Use Z tiles to filter out blocked views, if z1 is fully blocked by a opaque model, z2 -> zinfinite will never be seen

#### Light Filtering
 * CPU Collision checks
 * https://kayru.org/articles/deferred-stencil/
 * AABB
 * Compute Shader
#### Render Passes
 * Opaque (Deferred)
 * Volumetric (Raymarch)
    * Look at https://bartwronski.files.wordpress.com/2014/08/bwronski_volumetric_fog_siggraph2014.pdf
 * Transparent (Forward)
 * Custom passes (Forward)
    * Give ability to define number of custom passes
 