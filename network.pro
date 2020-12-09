%(200, 'ChangeMembraneNoise', 'N0', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N0', 0, 0)
%(200, 'ChangeMembraneNoise', 'N1', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N1', 0, 0)
%(200, 'ChangeMembraneNoise', 'N2', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N2', 0, 0)
%(200, 'ChangeMembraneNoise', 'N3', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N3', 0, 0)
%(200, 'ChangeMembraneNoise', 'N4', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N4', 0, 0)
%(200, 'ChangeMembraneNoise', 'N5', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N5', 0, 0)
%(200, 'ChangeMembraneNoise', 'N6', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N6', 0, 0)
%(200, 'ChangeMembraneNoise', 'N7', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N7', 0, 0)
%(200, 'ChangeMembraneNoise', 'N8', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N8', 0, 0)
%(200, 'ChangeMembraneNoise', 'N9', 1, 0.25)
%(300, 'ChangeMembraneNoise', 'N9', 0, 0)
%(1000, 'EndTrial')

%--------------------------------

EventTime 200
Type=ChangeMembraneNoise
Population: N0
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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
GaussMean=1
GaussSTD=0.25
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

FileName: ./compare/FiringRateALL100.dat
Type=FiringRate
population=AllPopulation
FiringRateWindow=100
PrintStep=10
EndOutputFile

EndOutControl
