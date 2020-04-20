# Tarea \#6 (Entregar antes de 30/04/2020)
## Curso de Estructura de Datos
---
## Problema 1. 
Dada una serie de enteros en un vector, devolver los índices de los dos números dentro del vector que se sumen un valor especificado.

Pueden suponer que cada entrada tendría exactamente una solución, y no puede usar el mismo elemento dos veces.
Example:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
Pueden resolvelo en linea en [url](https://leetcode.com/problems/two-sum/)

---
## Problema 2. 
Sedan dos listas ligadas no vacías que representan dos enteros no negativos. Los dígitos se almacenan en orden inverso y cada uno de sus nodos contiene un solo dígito. Agregue los dos números y devuélvalos como una lista ligada.

Pueden suponer que los dos números no contienen ningún cero inicial, excepto el número 0 en sí.
Ejemplo:
```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};
```
Pueden resolvelo en linea en [url](https://leetcode.com/problems/add-two-numbers/)

---
## Problema 3. 
Dada una cadena de caracteres, encuentra la longitud de la subcadena más larga sin repetir caracteres.(Sugerencia: Usen una tabla hash para saber si un caracter aparece o no)

Example 1:
```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```
Example 2:
```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
Example 3:
```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
Pueden resolver una versión un poco más dificil en linea en [url](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

---
## Problema 4. 
Dados dos árboles binarios, escriba una función para verificar si son iguales o no.

Dos árboles binarios se consideran iguales si son estructuralmente idénticos y los nodos tienen el mismo valor.

Example 1:
```
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
```
Example 2:
```
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
```
Example 3:
```
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
```
Pueden resolver una versión un poco más dificil en linea en [url](https://leetcode.com/problems/same-tree/)



## Problema 5(Bonus extra no obligatorio). 
Dado un entero con signo de 32 bits, invierte los dígitos de un entero.

Example 1:
```
Input: 123
Output: 321
```
Example 2:
```
Input: -123
Output: -321
```
Example 3:
```
Input: 120
Output: 21
```
Pueden resolver una versión un poco más dificil(pide considerar overflow) en linea en [url](https://leetcode.com/problems/reverse-integer/)