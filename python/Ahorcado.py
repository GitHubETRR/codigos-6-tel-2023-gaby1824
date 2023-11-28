import random
import pickle

file = open('dictionary', 'rb')
palabra = pickle.load(file)

Palabra_a_adivinar = random.choice(palabra).lower().replace("á", "a").replace("é", "e").replace("í", "i").replace("ó", "o").replace("ú", "u")
Palabra_split = [i for i in Palabra_a_adivinar]
Adivinar = ["_"]*len(Palabra_split)
vida = int(len(Palabra_a_adivinar)*0.5+4)
Adivino = False
Iguales = False
Adivinadas = []

print("Bienvenido al juego del ahorcado")
eleccion = input("Escriba 1 para comenzar a jugar: ")
if eleccion == '1':
    print(Adivinar)
    while (vida>0 and Iguales == False):
        Adivino = False
        Iguales = True

        print("="*50)
        Caracter = input("Ingrese una letra: ")
        Adivinadas.append(Caracter)
        for i in range(len(Palabra_split)):
            if Palabra_split[i] == Caracter:
                Adivinar[i] = Palabra_split[i]
                Adivino = True
            
            if Palabra_split[i] != Adivinar[i]:
                Iguales = False

        if Adivino == False:
            vida-=1

        print(f"Letras ya intentadas: {Adivinadas}")
        print(f"Intentos restantes: {vida}")
        print(f"Palabra adivinada: {Adivinar}")

    print(Palabra_a_adivinar)
