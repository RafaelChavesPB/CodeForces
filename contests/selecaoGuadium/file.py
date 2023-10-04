def ValidationTestFactory(test, exception, error_message):
        def verification(value, name):
            if not test(value):
                raise exception(f'Erro de validação: {name} ' + error_message)
        return verification

validationTests = {
        'float':ValidationTestFactory(lambda value: isinstance(value, float) or isinstance(value, int), ValueError, 'não é um float.'),
        'positive':ValidationTestFactory(lambda value: value >= 0, ValueError, 'não é positivo'),
}

def validate(value, tests):
    for test in tests:
        validation[test](value)

def validadeInput(distancia, tempo, valorPorKM, valorPorMinuto):
    try:
        for test in ['float', 'positive']:
            validationTests[test](distancia, 'Distância em KM')
            validationTests[test](tempo, 'Tempo em minutos')
            validationTests[test](valorPorKM, 'Valor por KM')
            validationTests[test](valorPorMinuto, 'Valor por minuto')
        return True
    except Exception as err:
        print(err)
        return None

INFINITY = 10**18
taxSteps = [
            (-INFINITY, 0.00, lambda value: 0.00),
            (0.00, 6.00, lambda value: 0.10*value),
            (6.00, 15.00, lambda value: 0.15*value), 
            (15.00, 20.00, lambda value: 3.10), 
            (20.00, 30.00, lambda value: 0.20*value), 
            (30.00, INFINITY, lambda value: 6.00)
]

def obtainTaxValue(totalValue):
    for minValue, maxValue, taxValue in taxSteps:
       if minValue < totalValue and totalValue <= maxValue:
           return taxValue(totalValue)
    return None

   
def calcularValorTempo(tempo, valorPorMinuto):    
    return valorPorMinuto*tempo

def calcularValorDistancia(distancia, valorPorKM):
    return valorPorKM*distancia

def calcularTaxa(distancia, tempo, valorPorKM, valorPorMinuto):
    if validadeInput(distancia, tempo, valorPorKM, valorPorMinuto):
        total = calcularValorDistancia(distancia, valorPorKM) + calcularValorTempo(tempo, valorPorMinuto)
        return obtainTaxValue(total)
    else:
        return None


if __name__ == '__main__':
    valorPorKM = 1.0
    valorPorMinuto = 1.0
    # (distancia, tempo)
    taxaTotal = 0
    quantidadeDeCorridas = 0
    # Um valor para cada tipo da tabela
    valoresTestes = ((0, 0), (3.0, 3.0), (7.5, 7.5), (10.00, 10.00), (15.00, 15.00), (20.0, 20.0))
    # Valores para nivel 1 da tabela
    valoresTestes1 = ((3.0, 3.0), (3.0, 3.0), (3.0, 3.0))
    # Valores para nivel 2 da tabela
    valoresTestes2 = ((7.5, 7.5),(7.5, 7.5),(7.5, 7.5))
    # Valores para nivel 3 da tabela
    valoresTestes3 = ((10.00, 10.00),(10.00, 10.00),(10.00, 10.00))
    # Valores para nivel 4 da tabela
    valoresTestes4 = ((15.00, 15.00),(15.00, 15.00),(15.00, 15.00))
    # Valores para nivel 5 da tabela
    valoresTestes5 = ((20.0, 20.0),(20.0, 20.0),(20.0, 20.0))
    # Valores para teste de robustez contra erros
    valoresTestesInvalidos = (('123.2','123.2'),(-1, -1), (0.00, -0.001))

    # Altere a tupla que o for itera de acordo com o teste
    for distancia, tempo in valoresTestesInvalidos:
        taxaAtual = calcularTaxa(distancia, tempo, valorPorKM, valorPorMinuto)
        if taxaAtual is None:
            continue
        taxaTotal += taxaAtual
        quantidadeDeCorridas += 1
    taxaMedia = taxaTotal/max(quantidadeDeCorridas,1)
    print(f'Taxa total: {taxaTotal:.2f}')
    print(f'Taxa média: {taxaMedia:.2f}')

### COMO EXECUTAR: python3 file.py



