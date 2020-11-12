%(200, 'ChangeMembraneNoise', 'neuron0', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron0', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron1', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron1', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron2', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron2', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron3', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron3', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron4', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron4', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron5', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron5', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron6', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron6', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron7', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron7', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron8', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron8', 0, 2)
%(200, 'ChangeMembraneNoise', 'neuron9', 4, 2)
%(300, 'ChangeMembraneNoise', 'neuron9', 0, 2)
%(1000, 'EndTrial')

%--------------------------------

EventTime 200
Type=ChangeMembraneNoise
Population: neuron0
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron0
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron1
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron1
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron2
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron2
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron3
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron3
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron4
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron4
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron5
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron5
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron6
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron6
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron7
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron7
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron8
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron8
GaussMean=0
GaussSTD=2
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: neuron9
GaussMean=4
GaussSTD=2
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: neuron9
GaussMean=0
GaussSTD=2
EndEvent

EventTime 1000
Type=EndTrial
EndEvent


%--------------------------------

OutControl

FileName: FiringRateALL.dat
Type=FiringRate
population=AllPopulation
FiringRateWindow=100
PrintStep=10
EndOutputFile

FileName: SpikeALL.dat
Type=Spike
population=AllPopulation
EndOutputFile

FileName: MemPot.dat
Type=MemPot
population=AllPopulation
EndOutputFile

EndOutControl
