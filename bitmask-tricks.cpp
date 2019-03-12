// iterar submascaras de una mascara de manera eficiente.
for(int subMask = mask; ; subMask = mask & (subMask-1)) {
    // utilizar subMask
    if(!subMask) break;
}
