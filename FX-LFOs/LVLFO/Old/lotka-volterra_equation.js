inlets = 1 + 4; // bang to run equations + variable updaters + smoothing
outlets = 1; // vector of species sizes

var N = jsarguments[1];

// globals
var Xs = [N]; // population sizes
var Rs = [N]; // birth rates
var Ks = [N]; // carrying capacities
var As = createArray(N,N); // effects of species on other species

randomInit();

var constantBirthRate = 0.001;
var smoothing = 0.95;

function setSpeciesCount(input)
{
	N = input;
	init();
}

function setSmoothing(input)
{
	smoothing = input;

}
function init() {
		for(var i = 0; i < N; i++) {
			Xs[i] = 0.1; // small pop. to start out with
			Rs[i] = Math.random(0.5, 1.5); // random growth/death
			Ks[i] = 1; // carrying capacity
		}
		As = createArray(N,N);
}

function randomInteractions()
{
	for(var i = 0; i < N; i++) {
		for(var j = 0; j < N; j++) {
			if(i == j) {
				As[i][j] = 1;
			} else {
				As[i][j] = Math.random(1.0, 1.5);
			}
		}
	}
}

function randomBirthRates()
{
	for(var i = 0; i < N; i++) {
		Rs[i] = Math.random(0.5, 1.5); // random growth/death
	}
}

function randomInit()
{

	for(var i = 0; i < N; i++) {
		Xs[i] = 0.1; // small pop. to start out with
		Rs[i] = Math.random(0.5, 1.5); // random growth/death
		Ks[i] = 1; // carrying capacity
		for(var j = 0; j < N; j++) {
			if(i == j) {
				As[i][j] = 1;
			} else {
				As[i][j] = Math.random(1.0, 1.5);
			}
		}	
	}
}

function list(l)
{
	
	switch(inlet)
	{
		case 1:
			Xs = arrayfromargs(arguments);
			break;
		case 2:
			Rs = arrayfromargs(arguments);
			break;
		case 3:
			Ks = arrayfromargs(arguments);
			break;
		case 4:
			var tempAs = arrayfromargs(arguments);
			for(var i = 0; i < N; i++) {
				for(var j = 0; j < N; j++) {
					As[i][j]=tempAs[i+j];
				}
			}
			break;
	}
	
}

function bang()
{
	for(var i = 0; i < N; i++) {
		var summation = 0;
		for(var j = 0; j < N; j++) {
			summation += As[i][j] * Xs[j];
		}
		var interSpeciesEffects = 1 - (summation / Ks[i]);
		//post("interSpeciesEffects: "+interSpeciesEffects+"\n");
		var update = Rs[i] * Xs[i] * interSpeciesEffects;
		//post("update: "+update+"\n");
		Xs[i] = Xs[i]*smoothing + (update + constantBirthRate)+(1-smoothing); // update population size
		
		// bound to [0.01,1]
		if(Xs[i] > 1.0) Xs[i] = 1.0;
		if(Xs[i] < 0.01) Xs[i] = 0.01;
	}
	outlet(0, Xs.slice());
}

function createArray(length) {
    var arr = new Array(length || 0),
        i = length;

    if (arguments.length > 1) {
        var args = Array.prototype.slice.call(arguments, 1);
        while(i--) arr[length-1 - i] = createArray.apply(this, args);
    }

    return arr;
}
