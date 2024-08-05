import numpy as np

def simular_disparos(n : int , l : float) -> float:
    '''
    parameters
    -----------
        n : int 
            Numero de disparos.

        l : float 
            Tamanho do lado do quadrado.

    returns
    -------
        razao : float
            Proporção de disparos certos e o total.

    '''
    # Inicia o lado do quadrado em questão, consequentemente o raio
    lado = l
    raio = lado/2

    total_disparos = 0
    disparos_certos = 0
    
    for disparo in range(n):
        # Onde o disparo caiu
        x = np.random.uniform(0,l)
        y = np.random.uniform(0,l)
        distancia_centro = ((x-raio)**2 + (y-raio)**2)**0.5

        if distancia_centro <= raio:
            disparos_certos+=1
        
        total_disparos += 1
       
    razao = disparos_certos / total_disparos

    return razao

# Questão 1
razao = simular_disparos(10000, 1)
print(razao)
print(4*razao)