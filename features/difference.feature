# language: es
Característica: Diferencia

  Escenario: Hacer la diferencia de dos conjuntos numericos
	Dado que tengo dos conjuntos de numeros:
		| conjunto_1 | conjunto_2 |
		| 20         | 30         |
		| 2          | 40         |
		| 0          | 20         |
    Cuando realizo la diferencia entre los conjuntos de numeros
    Entonces obtengo el conjunto de numeros resultado:
        | conjunto_resultado |
		| 0                  |
		| 2                  |

  Escenario: Hacer la diferencia de dos conjuntos de nombres
    Dado que tengo dos conjuntos de nombres:
        | conjunto_1 | conjunto_2 |
        | Juan       | Maria      |
        | Maria      | Tomas      |
        | Cecilia    | Agustina   |
        | Martin     | Leonardo   |
        | Leonardo   | Pedro      |
	Cuando realizo la diferencia entre los conjuntos de nombres
	Entonces obtengo el conjunto de nombres resultado:
        | conjunto_resultado |
        | Cecilia            |
        | Juan               |
        | Martin             |
