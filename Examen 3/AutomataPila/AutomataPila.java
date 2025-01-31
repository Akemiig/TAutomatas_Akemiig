package AutomataPila;

import java.util.Stack;

public class AutomataPila {
    private Stack<String> stack;

    public AutomataPila() {
        this.stack = new Stack<>();
    }

    public boolean validar(String entrada, StringBuilder transiciones) {
        transiciones.append("Entrada: ").append(entrada).append("\n\n");

        // Inicializar la pila con la regla inicial Es
        printTransicion("q0", "ε", "ε", "q1", "$", transiciones);
        stack.push("$");
        printTransicion("q1", "ε", "ε", "q2", "Es", transiciones);
        stack.push("Es");

        int index = 0; // indice de la cadena a validar

        while(!stack.isEmpty()) {
            String top= stack.pop(); // sacar el tope de la pila

            if(top.equals("Es")) {
                stack.push("En");
                stack.push("S");
                printTransicion("q2", "ε", "Es", "q2", "S En", transiciones);

            } else if (top.equals("S")) {
                if(index < entrada.length() && (entrada.charAt(index) == '+' || entrada.charAt(index) == '-')) {
                    char simbolo= entrada.charAt(index);
                    printTransicion("q2", "ε", "S", "q2", String.valueOf(simbolo), transiciones);
                    index++; // avanzar en la cadena
                    printTransicion("q2", String.valueOf(simbolo), String.valueOf(simbolo), "q2", "ε", transiciones);
                } else {
                    printTransicion("q2", "ε", "S", "q2", "ε", transiciones);
                }

            } else if (top.equals("En")) {
                stack.push("R");
                stack.push("D");
                printTransicion("q2", "ε", "En", "q2", "D R", transiciones);

            } else if (top.equals("D")) {
                if(index < entrada.length() && Character.isDigit(entrada.charAt(index))) {
                    char numero = entrada.charAt(index);
                    printTransicion("q2", "ε", "D", "q2", String.valueOf(numero), transiciones);
                    index++; // avanzar en la cadena
                    printTransicion("q2", String.valueOf(numero), String.valueOf(numero), "q2", "ε", transiciones);
                } else {
                    transiciones.append("Error: Se esperaba un dígito.\n");
                    return false;
                }

            } else if(top.equals("R")) {
                if(index== entrada.length()) {
                    printTransicion("q2", "ε", "R", "q2", "ε", transiciones);
                    printTransicion("q2", "ε", "$", "q3", "ε", transiciones);
                    return true;
                } else{
                    stack.push("R");
                    stack.push("D");
                    printTransicion("q2", "ε", "R", "q2", "D R", transiciones);
                }
            }
        }

        return false; // si la pila se vacía sin aceptar la cadena
    }

    private void printTransicion(String estadoActual, String entrada, String cima, String estadoSiguiente, String nuevaCima, StringBuilder transiciones) {
        transiciones.append("δ (" + estadoActual + ", " + entrada + ", " + cima + "; " + estadoSiguiente + ", " + nuevaCima + ") \n");
    }
}
