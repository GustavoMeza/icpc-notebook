// Para generar randoms
uniform_int_distribution<int>dist(0, n); // La distribución de los numeros, intervalos inclusivos
uniform_real_distribution<double>dist(0, n); // La distribución de los numeros, intervalos inclusivos
random_device rd; // Tarda en ejecutarse, genera buenos random, perfecto para usar como semilla
mt19937 engine(rd()); // Rapido de ejecutar, necesita una semilla que aporta rd()
