# Abstract Integer App

## Enunciado
Diseñar la clase Integer que implementa el Tipo de Dato Abstracto Número entero, que almacena los dígitos del número en un arreglo dinámico de enteros y que cuenta, además de los constructores y el destructor, con los siguientes operadores sobrecargados (como funciones no miembros):

:heavy_plus_sign: : para sumar dos números enteros,

:heavy_minus_sign: : para restar un número entero de otro,

:heavy_multiplication_x: : para multiplicar dos números enteros,

Requisitos de diseño:
- Ninguna de las operaciones solicitadas deberá convertir el (los) número(s) entero(s) para operar con él (ellos).
- Las operaciones solicitadas deberán ser implementadas de la manera más eficiente posible, para lo cual se podrán utilizar trucos de programación que así lo garanticen.
- Tanto el constructor de inicialización, como el método de acceso de escritura reciben un número entero y lo almacena, de manera adecuada, en el arreglo.
- Tanto el método de acceso de lectura, como las operaciones solicitadas deberán devolver un número entero, y no el arreglo.
- En el caso de la multiplicación, se implementará en dos variantes: por el método tradicional de multiplicación de enteros y por el método de Karatsuba. Para ello, la clase deberá contar con un puntero a función (como atributo protegido) que almacena la dirección de uno de estos dos métodos, a demanda del usuario de la aplicación. Para ello, la clase contará con un método de acceso de escritura para ese atributo, que se utiliza cuando el usuario elige la variante de multiplicación que desea emplear y el operador * realiza la multiplicación mediante la variante elegida.

Se deberá diseñar una aplicación que permita realizar estas operacioens con solo dos instancias de la clase para los que el usuario puede modificar su valor cuando desee. Cuando el usuario solicite la multiplicación, la aplicación deberá hallar el resultado por ambas variantes y mostrar el tiempo que tomó realizar cada una de ellas, a modo de comparación.
Sugerencia:
Buscar el algoritmo de Karatsuba en mathworld.wolfram.com (sitio oficial internacional de matemáticas).