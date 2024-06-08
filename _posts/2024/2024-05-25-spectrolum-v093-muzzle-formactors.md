---
layout: post
title: Muzzle form factors
categories: spectrolum
version: v0.93
excerpt: "Coding of Muzzle form factors"
tags:
  - spectrometer
  - xspectrolum
  - sensors
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2024-05-25'
modified: '2024-05-25'
comments: true
share: true
---

### Light codes

Light code keys
| attribute | position | expression | code |
| sample state | 1 | solid | 1 | 
| sample state | 1 | liquid | 2 | 
| sample state | 1 | gaseous | 3 |
| sample state | 1 | plasma | 4 |
| sample state | 1 | other | 0 |
| Nr of lights | 2 | null  | 0 |
| Nr of lights | 2 | single  | 1 |
| Nr of lights | 2 | dual  | 2 |
| Nr of lights | 2 | triple  | 3 |
| Nr of lights | 2 | quadruple  | 4 |
| Signal | 3 | diffuse reflectance  | 1 |
| Signal | 3 | other reflectance  | 2 |
| Signal | 3 | absorbance  | 3 |
| Signal | 3 | fluorescence  | 4 |
| Signal | 3 | raman  | 5 |
| Signal | 3 | other  | 0 |
| light source/bandwidth | 4 | single band laser | 1 |
| light source/bandwidth | 4 | single band LED | 2 |
| light source/bandwidth | 4 | broad band LED visible [VIS]  | 3 |
| light source/bandwidth | 4 | broad band LED near infrared [NIR]  | 4 |
| light source/bandwidth | 4 | broad band LED VIS+NIR  | 5 |
| light source/bandwidth | 4 | broad band LED Mid IR [MIR]  | 6 |
| light source/bandwidth | 4 | incandescent bulb tungsten | 7 |
| light source/bandwidth | 4 | incandescent bulb halogen  | 8 |
| light source/bandwidth | 4 | incandescent bulb xenon  | 9 |
| light source/bandwidth | 4 | other light source | 0 |
| Wavelength/band region | 5-8 | single peak in nm | XYZ [e.g. 555] |
| Wavelength/band region | 5-8 | VIS | VIS |
| Wavelength/band region | 5-8 | NIR | NIR |
| Wavelength/band region | 5-8 | MIR | MIR |
| Wavelength/band region | 5-8 | VIS+NIR | VINI |
| Wavelength/band region | 5-8 | NIR+MIR | NIMI |
| Wavelength/band region | 5-8 | Full spectrum incandescent | HOT |

Examples
| state | width | height | restriction | color | code |
| solid | narrow | small | none | black | sns00 |
| solid | wide | large | none | red | swl0r |


### Form factor

Form factor keys

| attribute | position | expression | code |
| sample state | 1 | solid | s | 
| sample state | 1 | liquid | l | 
| sample state | 1 | gaseous | g |
| sample state | 1 | plasma | p |
| width | 2 | narrow  |  n |
| width | 2 | wide | w |
| height | 3 | small | s |
| height | 3 | medium | m |
| height | 3 | large | l |
| height | 3 | extra large | x |
| focus | 4 | none | 0 |
| focus | 4 | brim | 1 |
| focus | 4 | reflector | 2 |
| focus | 4 | collimator | 3 |
| color | 5 | black | 0 |
| color | 5 | blue | b |
| color | 5 | green | g |
| color | 5 | yellow | y |
| color | 5 | cyan | c |
| color | 5 | magenta | m |
| color | 5 | violet | v |
| color | 5 | white | w |



Form factor example codes
| state | width | height | restriction | color | code |
| solid | narrow | small | none | black | sns00 |
| solid | wide | large | none | red | swl0r |
