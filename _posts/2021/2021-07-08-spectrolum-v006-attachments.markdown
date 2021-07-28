---
layout: post
title: Attachments v0.06
categories: spectrolum
version: "v0.06 attachments"
tags:
  - spectrometer
  - stulturum
  - v0.06
  - attachments
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-07-08'
modified: '2021-07-08'
comments: true
share: true
---

## Stulturum spectrometer version v0.06 attachemnts

Version 0.06 of xSpectres spectrometers is built using the Arduino [NANO IOT 33 board](http://localhost:4000/module/module-nano-iot-33/). All versions in the 0.06 series (regardless of spectrometer) can use the same set of attachments - or samplers.

<figure>
<img src="../../images/xspectre_spectrometer+attachments_v06.png">
<figcaption>xSpectre spectromter v 0.6x with some of the available attachments </figcaption>
</figure>

The sample attachments all have two properties: 1) an emission source, and 2) a sample space. The emission source is typically a Light Emitting Diode (LED), laser or other light bulb. The sample space is either open (to be held directly against any surface), for ground (or solid) samples, or for liquids in a cuvette. A gas sampler is under development. Samplers that only use the xSpectre spectrometer as a light source and that can attach a fibre optic cable are also under development.

Available [x] and planned [o] attachment samplers for xSpectre version 0.6.

| Light source | open | solid | liquid | gas | x-solid | x-liquid |
| White LED | x | x | x | o | o | o |
| Blue LED | x | x | x | o | o | o |
| NIR LED | x | x | x | o | x | o |
| Xenon | x | x | x | o | x | o |
| Red laser | x | x | x | o | o | o |
| Green laser | - | x | x | - | - | - |

### Spectrometer sampler and light source attachments

![trx-connector](../../images/trx_connector_female-male.png)
{: .pull-right}
All sampler attachments are connected to the xSpectre spectrometer using a TRX connection (right). For the open, ground (solid) and cuvette samplers, the TRX connector also holds the sampler in place in front of the spectrometer. Samplers for solids and liquids also exists as stand alone samplers with the spectral signal picked up via an SMA905 connection to a fibre optic cable. These samplers are powered via a JST connector (see below).

### Open sampler

The open sampler is intended for being held directly against any object. As stray light will almost inevitable affect the spectral analysis, it is not an ideal method (unless performed in pitch dark conditions).

#### Open sampler with white or blue LED

White and blue LED have the same dimensions and the 3D designed (<span class='file'>stl</span> file) model is the same ([spectro-direct-cyl-led_20210606_v061d.stl](../../stl/spectro-direct-cyl-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-direct-cyl-led_20210606_v061d.png">
<figcaption> Open sampler for white and blue LED. </figcaption>
</figure>

#### Open sampler with NIR LED

![osram](../../images/spectro-osram-NIR-holder_20210704_v062a.png)
{: .pull-right}
The [Near Infra-Red (NIR) LED](../../component/component-osram-ir-led) used in version 0.06 is an outdated OSRAM LED that is still available from [Farnell](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?mckv=smU6KqYGs_dc%7Cpcrid%7C417071399973%7Ckword%7Csfh%204735%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C97784419567%7Cptaid%7Ckwd-346858407321%7C&CMP=KNC-GSE-GEN-SKU-MDC). I first print a small holder ([spectro-osram-NIR-holder_20210704_v062a.stl](../../stl/spectro-osram-NIR-holder_20210704_v062a.stl)) and solder wires to the LED and then glue it into the holder. I then put the small holder into the open sampler for NIR LED ([spectro-direct-cyl-led_20210606_v061d.stl](../../stl/spectro-direct-cyl-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-direct-cyl-osram_20210606_v061d.png">
<figcaption> Open sampler for NIR LED. </figcaption>
</figure>

#### Open sampler with xenon

The xenon light I use is the 3 volt and 300 mA from Barthelme and available from [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267), it has a diameter of 3mm and a length of 10.5 mm.

![led3mm-neopren](../../images/led-socket_neopren_3mm.png)
{: .pull-right}
The xenon does not have any dedicated anode or cathode. I fit it into the 3d printed sampler ([spectro-direct-cyl-xenon_20210606_v061d.stl](../../stl/spectro-direct-cyl-xenon_20210606_v061d.stl)) using a soft (rubber) holder for micro (3 mm) LEDs (right) available from e.g. [Conrad.se](https://www.conrad.se/p/donau-elektronik-3-sc-led-sockel-gummi-passar-till-led-3-mm-184802?gclid=CjwKCAjw55-HBhAHEiwARMCszgs7wSEUVypO8sg5Gf369w_X0Fe_D3T66v2WL6rI3zTB8Ku7pH4cZRoCKWwQAvD_BwE&gclsrc=aw.ds&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_medium=surfaces&utm_source=google&utm_term=184802&vat=true).

<figure>
<img src="../../images/spectro-direct-cyl-xenon_20210606_v061d.png">
<figcaption> Open sampler for xenon bulb.</figcaption>
</figure>

#### Open sampler with red laser

The [red laser](../../component-laser650) sampler ([spectro-direct-cyl-red-laser_20210606_v061d.stl](../../stl/spectro-direct-cyl-red-laser_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-direct-cyl-red-laser_20210606_v061d.png">
<figcaption> Open sampler for red laser.</figcaption>
</figure>

### Grind (solid) sampler

![grind-dish](../../images/spectro-solid-holder_20210707_v062a.png)
{: .pull-right}
The grind or solid sampler comes with a small dish to hold the sample ([spectro-solid-holder_20210707_v062a.stl](../../stl/spectro-solid-holder_20210707_v062a.stl)). The solid samplers are identical to the open samplers, except that the ring is longer to fit the sample dish.

#### Solid sampler with white or blue LED

White and blue LED have the same dimensions and the 3d designed (<span class='file'>stl</span> file) model is the same ([spectro-solid-cyl-led_20210606_v061d.stl](../../stl/spectro-solid-cyl-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-solid-cyl-led_20210606_v061d.png">
<figcaption> Solid sampler for white and blue LED. </figcaption>
</figure>

#### Solid sampler with NIR LED

![osram](../../images/spectro-osram-NIR-holder_20210704_v062a.png)
{: .pull-right}
The [Near Infra-Red (NIR) LED](../../component/component-osram-ir-led) used in version 0.06 is an outdated OSRAM LED that is still available from [Farnell](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?mckv=smU6KqYGs_dc%7Cpcrid%7C417071399973%7Ckword%7Csfh%204735%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C97784419567%7Cptaid%7Ckwd-346858407321%7C&CMP=KNC-GSE-GEN-SKU-MDC). I first print a small holder ([spectro-osram-NIR-holder_20210704_v062a.stl](../../stl/spectro-osram-NIR-holder_20210704_v062a.stl)) and solder wires to the LED and then glue it into the holder. I then put the small holder into the solid sampler for NIR LED ([spectro-solid-cyl-led_20210606_v061d.stl](../../stl/spectro-solid-cyl-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-solid-cyl-osram_20210606_v061d.png">
<figcaption>Solid sampler for NIR LED. </figcaption>
</figure>

#### Solid sampler with xenon

The xenon light I use is the 3 volt and 300 mA from Barthelme and available from [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267), it has a diameter of 3mm and a length of 10.5 mm.

![led3mm-neopren](../../images/led-socket_neopren_3mm.png)
{: .pull-right}
The xenon does not have any dedicated anode or cathode. I fit it into the 3d printed sampler ([spectro-direct-cyl-xenon_20210606_v061d.stl](../../stl/spectro-direct-cyl-xenon_20210606_v061d.stl)) using a soft (rubber) holder for micro (3 mm) LEDs (right) available from e.g. [Conrad.se](https://www.conrad.se/p/donau-elektronik-3-sc-led-sockel-gummi-passar-till-led-3-mm-184802?gclid=CjwKCAjw55-HBhAHEiwARMCszgs7wSEUVypO8sg5Gf369w_X0Fe_D3T66v2WL6rI3zTB8Ku7pH4cZRoCKWwQAvD_BwE&gclsrc=aw.ds&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_medium=surfaces&utm_source=google&utm_term=184802&vat=true).

<figure>
<img src="../../images/spectro-solid-cyl-xenon_20210606_v061d.png">
<figcaption> Solid sampler for xenon bulb.</figcaption>
</figure>

#### Solid sampler with red laser

The [red laser](../../component/component-laser650) sampler ([spectro-solid-cyl-red-laser_20210606_v061d.stl](../../stl/spectro-solid-cyl-red-laser_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-solid-cyl-red-laser_20210606_v061d.png">
<figcaption> Solid sampler for red laser.</figcaption>
</figure>

#### Solid sampler with green laser

Not yet available.

### Cuvette (liquid) sampler

The cuvette or liquid sampler is composed of two parts, a connection part that links the TRX and the cuvette part, and the cuvette part. The 2 part solution is required for getting accurate 3D printed openings in all direction. The connection part is the same for all different version of the cuvette sampler.

#### TRX to cuvette connection part

The TRX foundation (link) part that have perpendicular openings for hloding the TRX male connector and the actual cuvette holder ([spectro-cuvette-trx_20210606_v061d.stl)](../../stl/spectro-cuvette-trx_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-cuvette-trx_v061.png">
<figcaption> TRX link/foundation that links all cuvette samplers to the container). </figcaption>
</figure>

#### Cuvette sampler with white LED

The white LED cuvette sampler is for measuring absorbance and the light source is positioned on the opposite side of the cuvette compared to the spectral sensor ([spectro-cuvette-back-led_20210606_v061d.stl](../../stl/spectro-cuvette-back-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-cuvette-back-led_20210606_v061d.png">
<figcaption> cuvette sampler for white led. </figcaption>
</figure>

#### Cuvette sampler with xenon

The xenon cuvette sampler is also for measuring the absorbance  ([spectro-cuvette-xenon_20210606_v061d.stl](../../stl/spectro-cuvette-xenon_20210606_v061d.stl)).

The xenon light I use is the 3 volt and 300 mA from Barthelme and available from [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267), it has a diameter of 3mm and a length of 10.5 mm.

![led3mm-neopren](../../images/led-socket_neopren_3mm.png)
{: .pull-right}
The xenon light bulb is fitted into the  sampler using a soft (rubber) holder for micro (3 mm) LEDs (right) available from e.g. [Conrad.se](https://www.conrad.se/p/donau-elektronik-3-sc-led-sockel-gummi-passar-till-led-3-mm-184802?gclid=CjwKCAjw55-HBhAHEiwARMCszgs7wSEUVypO8sg5Gf369w_X0Fe_D3T66v2WL6rI3zTB8Ku7pH4cZRoCKWwQAvD_BwE&gclsrc=aw.ds&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_medium=surfaces&utm_source=google&utm_term=184802&vat=true).

<figure>
<img src="../../images/spectro-cuvette-xenon_20210606_v061d.png">
<figcaption>Cuvette sampler for xenon bulb. </figcaption>
</figure>

#### Cuvette sampler with NIR LED

![osram](../../images/spectro-osram-NIR-holder_20210704_v062a.png)
{: .pull-right}
The [Near Infra-Red (NIR) LED](../../component/component-osram-ir-led) used in version 0.06 is an outdated OSRAM LED that is still available from [Farnell](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?mckv=smU6KqYGs_dc%7Cpcrid%7C417071399973%7Ckword%7Csfh%204735%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C97784419567%7Cptaid%7Ckwd-346858407321%7C&CMP=KNC-GSE-GEN-SKU-MDC). I first print a small holder ([spectro-osram-NIR-holder_20210704_v062a.stl](../../stl/spectro-osram-NIR-holder_20210704_v062a.stl)) and solder wires to the LED and then glue it into the holder. I then put the small holder into the solid sampler for NIR LED ([spectro-solid-cyl-led_20210606_v061d.stl](../../stl/spectro-solid-cyl-led_20210606_v061d.stl)).

Also for absorbance. Not yet available.

#### Cuvette sampler with blue LED

Blue LED is used for fluorescence spectroscopy, with the light source preferable placed perpendicular to the spectral sensor  ([spectro-cuvette-blue-led_20210606_v061d.stl](../../stl/spectro-cuvette-blue-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-cuvette-blue-led_20210606_v061d.png">
<figcaption>Cuvette sampler for blue LED. </figcaption>
</figure>

#### Cuvette sampler with red laser

Spectral analysis with a single wavelength laser (e.g. red or green) is for Raman spectroscopy. The light source is placed perpendicular to the spectral sensor. The 3D model for red laser cuvette sampler ([spectro-cuvette-red-laser_20210606_v061d.stl](../../stl/spectro-cuvette-red-laser_20210606_v061d.stl))

<figure>
<img src="../../images/spectro-cuvette-red-laser_20210606_v061d.png">
<figcaption>Cuvette sampler for red laser. </figcaption>
</figure>

#### Cuvette sampler with green laser

The 3D model for green laser cuvette sampler includes space for dc-dc step module to reach 5 volt for the green laser module used with version 0.6 ([spectro-cuvette-green-laser_20210606_v061d.stl](../../stl/spectro-cuvette-green-laser_20210606_v061d.stl))

<figure>
<img src="../../images/spectro-cuvette-green-laser_20210606_v061d.png">
<figcaption>Cuvette sampler for green laser, including space for dc-dc step module. </figcaption>
</figure>

### Stand alone samplers

Stand alone samplers are identical to the attached samplers, but without any TRX connection. Instead the stand alone samplers have an opening for attaching fibre optic cables. The stand alone samplers are primarily for evaluation of the xSpectre spectrometers and light sources.

![sma-female](../../images/SMA905_female_collimator.png)
{: .pull-left}
The stand alone samplers are thus prepared for attaching a [fibre optic cable](../../blog/blog-fiber-optics) by embedding an SMA905 female connector with a collimating lens (left).

![sma-male](../../images/SMA905_male_fibre-optic-cable.png)
{: .pull-right}
sma905 double ended male cables (right) are the most common method for capturing the light the spectral signal to analyse in bench-top spectrometers. One end attaches to the stand alone sampler and the other to the bench top spectrometer.

![JST-kontaktdon](../../images/JST-kontaktdon_2-stifts.png)
{: .pull-left}
The power connection of the stand alone samplers are thus not used for holding the sampler in place in front of the xSpectre spectrometer. Power is instead supplied via a JST 2-pin connection (left).

<br/><br/>

#### stand alone solid sampler with LED

White and blue LED have the same dimensions and the 3d designed (<span class='file'>stl</span> file) model is the same ([x-spectro-solid-cyl-led_20210706_v062a.stl](../../stl/x-spectro-solid-cyl-led_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-solid-cyl-led_20210706_v062a.png">
<figcaption> stand alone solid sampler for white and blue LED. </figcaption>
</figure>

#### stand alone solid sampler with NIR LED

![osram](../../images/spectro-osram-NIR-holder_20210704_v062a.png)
{: .pull-right}
The [Near Infra-Red (NIR) LED](../../component/component-osram-ir-led) used in version 0.06 is an outdated OSRAM LED that is still available from [Farnell](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?mckv=smU6KqYGs_dc%7Cpcrid%7C417071399973%7Ckword%7Csfh%204735%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C97784419567%7Cptaid%7Ckwd-346858407321%7C&CMP=KNC-GSE-GEN-SKU-MDC). I first print a small holder ([spectro-osram-NIR-holder_20210704_v062a.stl](../../stl/spectro-osram-NIR-holder_20210704_v062a.stl)) and solder wires to the LED and then glue it into the holder. I then put the small holder into the solid sampler for NIR LED ([x-spectro-solid-cyl-osram_20210706_v062a.stl](../../stl/x-spectro-solid-cyl-osram_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-solid-cyl-osram_20210706_v062a.png">
<figcaption>stand alone solid sampler for NIR LED. </figcaption>
</figure>

#### stand alone solid sampler with xenon

The xenon light I use is the 3 volt and 300 mA from Barthelme and available from [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267), it has a diameter of 3mm and a length of 10.5 mm.

![led3mm-neopren](../../images/led-socket_neopren_3mm.png)
{: .pull-right}
The xenon does not have any dedicated anode or cathode. I fit it into the 3d printed sampler ([x-spectro-solid-cyl-xenon_20210706_v062a.stl](../../stl/x-spectro-solid-cyl-xenon_20210706_v062a.stl)) using a soft (rubber) holder for micro (3 mm) LEDs (right) available from e.g. [Conrad.se](https://www.conrad.se/p/donau-elektronik-3-sc-led-sockel-gummi-passar-till-led-3-mm-184802?gclid=CjwKCAjw55-HBhAHEiwARMCszgs7wSEUVypO8sg5Gf369w_X0Fe_D3T66v2WL6rI3zTB8Ku7pH4cZRoCKWwQAvD_BwE&gclsrc=aw.ds&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_medium=surfaces&utm_source=google&utm_term=184802&vat=true).

<figure>
<img src="../../images/x-spectro-solid-cyl-xenon_20210706_v062a.png">
<figcaption> stand alone solid sampler for xenon bulb.</figcaption>
</figure>

#### stand alone solid sampler with red laser

The [red laser](../../component/component-laser650) sampler ([x-spectro-solid-cyl-red-laser_20210706_v062a.stl](../../stl/sx-spectro-solid-cyl-red-laser_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-solid-cyl-red-laser_20210706_v062a.png">
<figcaption> stand alone solid sampler for red laser.</figcaption>
</figure>

#### stand alone solid sampler with green laser

Not yet available.

### stand alone cuvette sampler

The stand alone cuvette sampler has a larger base compared to the attached cuvette sampler that has a separate foundation. The wall holding the female SMA905 connector is also thicker to allow screwing it in properly.

#### stand alone cuvette sampler with white LED

The white LED stand alone cuvette sampler is for measuring the absorbance and the light source is positioned on the opposite side of the cuvette compared to the SMA female connector ([x-spectro-cuvette-back-led_20210606_v061d.stl](../../stl/x-spectro-cuvette-back-led_20210606_v061d.stl)).

<figure>
<img src="../../images/spectro-cuvette-back-led_20210706_v062a.png">
<figcaption>stand alone cuvette sampler for white led. </figcaption>
</figure>

#### stand alone cuvette sampler with xenon

The xenon cuvette stand alone sampler is also for measuring the absorbance ([x-spectro-cuvette-xenon_20210706_v062a.stl](../../stl/x-spectro-cuvette-xenon_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-cuvette-xenon_20210706_v062a.png">
<figcaption>stand alone cuvette sampler for xenon bulb. </figcaption>
</figure>

#### stand alone cuvette sampler with NIR LED

![osram](../../images/spectro-osram-NIR-holder_20210704_v062a.png)
{: .pull-right}
The [Near Infra-Red (NIR) LED](../../component/component-osram-ir-led) used in version 0.06 is an outdated OSRAM LED that is still available from [Farnell](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?mckv=smU6KqYGs_dc%7Cpcrid%7C417071399973%7Ckword%7Csfh%204735%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C97784419567%7Cptaid%7Ckwd-346858407321%7C&CMP=KNC-GSE-GEN-SKU-MDC). I first print a small holder ([x-spectro-cuvette-osram_20210706_v062a.stl](../../stl/x-spectro-cuvette-osram_20210706_v062a.stl)) and solder wires to the LED and then glue it into the holder. I then put the small holder into the stand alone cuvette sampler for NIR LED ([x-spectro-cuvette-osram_20210706_v062a.stl](../../stl/x-spectro-cuvette-osram_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-cuvette-osram_20210706_v062a.png">
<figcaption>stand alone cuvette sampler for NIR LED. </figcaption>
</figure>

#### stand alone cuvette sampler with blue LED

Blue LED is used for fluorescence spectroscopy, with the light source preferable placed perpendicular to the spectral sensor  ([x-spectro-cuvette-blue-led_20210706_v062a.stl](../../stl/x-spectro-cuvette-blue-led_20210706_v062a.stl)).

<figure>
<img src="../../images/x-spectro-cuvette-blue-led_20210706_v062a.png">
<figcaption>stand alone cuvette sampler for blue LED. </figcaption>
</figure>

#### Stand alone cuvette sampler with red laser

Spectral analysis with a single wavelength laser (e.g. red or green) is for Raman spectroscopy. The 3D model for red laser cuvette sampler ([x-spectro-cuvette-red-laser_20210706_v062a.stl](../../stl/x-spectro-cuvette-red-laser_20210706_v062a.stl))

<figure>
<img src="../../images/x-spectro-cuvette-red-laser_20210706_v062a.png">
<figcaption>Stand alone cuvette sampler for red laser. </figcaption>
</figure>

#### Stand alone cuvette sampler with green laser

The 3D model for green laser cuvette sampler includes space for dc-dc step module to reach 5 volt for the green laser module used with version 0.6 ([spectro-cuvette-green-laser_20210606_v061d.stl](../../stl/spectro-cuvette-green-laser_20210606_v061d.stl))

not yet available
