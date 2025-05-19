
# EcoBaubles
ᵇᶦᵇᵇˡᵉ ᵇᵒᵇᵇˡᵉ

Ecologically informed VST Plug-ins and M4L Devices for sound creation and manipulation. 

Crystal Circuits Series / Modeling Natural Systems Series

Extensions of Eli Stine's 2019 dissertation, [*Modeling Natural Systems in Immersive Electroacoustic Music*](http://www.elistine.com/diss).


## Plug-ins

![](https://github.com/estine/ecobobbles/blob/main/Mockups_for_EcoBobbles_GUIs.png)

- #### Generator-Processors

    - [*MurMini* — Flocking Simulation-Driven Granular Synthesizer](https://github.com/estine/ecobobbles/tree/main/Generator-Processors/MurMini)
    
   
    ![](https://github.com/estine/ecobobbles/blob/main/Murm_Vid_Short_Comp.gif)
    
    - [*AcousTransMini* — Acoustic Niche Hypothesis-Informed Sound Mapper](https://github.com/estine/ecobobbles/tree/main/Generator-Processors/AcousTransMini)
    
    ![](https://github.com/estine/ecobobbles/blob/main/AcousMIDI_v0.png)

  *Miarolitique* - Druse-inspired Arpeggiator

- #### FX-LFOs
    - [*EvoFX* - Evolutionary Algorithm Controlled Effects Rack](https://github.com/estine/ecobobbles/tree/main/FX-LFOs/EvoFX)
    - [*LVLFO* - Predator-Prey Model (Lotka–Volterra Equations) LFO Bank](https://github.com/estine/ecobobbles/tree/main/FX-LFOs/LVLFO)

- #### Other (TBD)
    - Data Sonifier - load in a file, sonify it horizontally, vertically, parametrically, etc.
![](https://images.squarespace-cdn.com/content/v1/56536248e4b07f927675796c/1532469671594-QCM6O9MSQGZT9CWUT8FS/pitter.png?format=2500w)

## Author(s)

- [@estine](https://www.github.com/estine)


## Goals / Hopes / Dreams

## Current Tasks

#### Crystal Circuits Series
- [ ] Miarolitique (deluxe arpeggiator inspired by the formation of crystal clusters, AKA Druses) version in RNBO
- [ ] Auralattice (crystallography inspired spatializer parameters generating plug-in) version in RNBO
- [ ] Crystallophon (crystal-inspired simple (?) physical modeling synthesizer) version in RNBO (?)
- [ ] Amphedra (piezo electricity inspired parameters (?) generating plug-in) version in RNBO

#### Modeling Natural Systems Series
- [ ] Lotka-Volterra Oscillator
- [ ] MurMini initial version in RNBO (granular synth with params. controlled by flock sim.)
- [ ] Make a GUI front in JUCE for the SimpleGlitcher (just attach some knobs / faders to it)

#### Export Targets
- RNBO exported VSTs without GUI (Max)
- RNBO- or JUCE- or HISE-created VSTs with GUI (Max, C++, Cmajor, Javascript)
- ~M4L devices for Ableton Live with GUI (Max)~

#### Design Principles
- Slick, pretty easy to evaluate and execute GUIs
- Comprehensive but not overwhelming parameter spaces (effective parameter multiplexing)
- Lots of audio demos and use within music
- Async as well as syncing to BPM and beat grid (essential!)

## Timeline

#### Phase I
- [ ] Mockup EcoBaubles in Max, semi-conscious of RNBO~ limitations, target is RNBO~ without GUIs
- [ ] Get functioning as VSTs using RNBO~, test within compositions

#### Phase II
- [ ] Explore mockup GUI design in JUCE/PGM/Other
- [ ] Create full-fledged, custom GUI versions in JUCE, based off of RNBO~

#### Phase III
- [ ] Documentation creation, final touches, and beta testing

#### Phase IV
- [ ] Release, promotion
