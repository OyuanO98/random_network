%(200, 'ChangeMembraneNoise', 'N0', 4, 0)
%(300, 'ChangeMembraneNoise', 'N0', 0, 0)
%(200, 'ChangeMembraneNoise', 'N1', 4, 0)
%(300, 'ChangeMembraneNoise', 'N1', 0, 0)
%(200, 'ChangeMembraneNoise', 'N2', 4, 0)
%(300, 'ChangeMembraneNoise', 'N2', 0, 0)
%(200, 'ChangeMembraneNoise', 'N3', 4, 0)
%(300, 'ChangeMembraneNoise', 'N3', 0, 0)
%(200, 'ChangeMembraneNoise', 'N4', 4, 0)
%(300, 'ChangeMembraneNoise', 'N4', 0, 0)
%(200, 'ChangeMembraneNoise', 'N5', 4, 0)
%(300, 'ChangeMembraneNoise', 'N5', 0, 0)
%(200, 'ChangeMembraneNoise', 'N6', 4, 0)
%(300, 'ChangeMembraneNoise', 'N6', 0, 0)
%(200, 'ChangeMembraneNoise', 'N7', 4, 0)
%(300, 'ChangeMembraneNoise', 'N7', 0, 0)
%(200, 'ChangeMembraneNoise', 'N8', 4, 0)
%(300, 'ChangeMembraneNoise', 'N8', 0, 0)
%(200, 'ChangeMembraneNoise', 'N9', 4, 0)
%(300, 'ChangeMembraneNoise', 'N9', 0, 0)
%(1000, 'EndTrial')

%--------------------------------

EventTime 200
Type=ChangeMembraneNoise
Population: N0
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N0
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N1
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N1
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N2
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N2
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N3
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N3
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N4
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N4
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N5
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N5
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N6
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N6
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N7
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N7
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N8
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N8
GaussMean=0
GaussSTD=0
EndEvent

EventTime 200
Type=ChangeMembraneNoise
Population: N9
GaussMean=4
GaussSTD=0
EndEvent

EventTime 300
Type=ChangeMembraneNoise
Population: N9
GaussMean=0
GaussSTD=0
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
