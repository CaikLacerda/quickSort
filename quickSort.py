#Quicksort
def quicksort(lista, inicio=0, fim=None):
    if fim is None:
        fim = len(lista)-1
    if inicio < fim:
        p = partition(lista, inicio, fim)
        quickSort(lista, inicio, p-1)
        quickSort(lista, p+1,fim)
    
def partition(lista, inicio, fim):
    pivot = lista[fim]

    # Barra amarela = i
    i = inicio
    # Barra roxa = j
    for j in range(inicio, fim):

        # Se a barra roxa for menor que o pivo, a barra amarela(i) ira avancar
        if lista[j] <= pivot:
            # swap para passar o valor menor que o pivo para a barra amarela
            lista[j], lista [i] = lista[i], lista[j]
            i  = i + 1
    # swap para passar o pivo para o fim da barra amarela
    lista[i], lista [fim]= lista[fim], lista [i]
    return i

