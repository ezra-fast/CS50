# TODO
import cs50  # Ici j'importe la bibliotheque 'cs50' entiere, alors quand un fonction cs50 est appeler, ont doit specifier la bibliotheque 'cs50'


def main():  # Ici je commence la fonction principale

    change = 0

    cents = cs50.get_float("Change owed: ")  # Je demande le nombre de 'cents' que l'utilisateur veut calculer avec le programme

    while cents <= 0.00:
        cents = cs50.get_float("Change owed: ")

    cents = round(int(cents * 100))  # Ici je converte le valeur 'cents' a une 'int', puisque je le 'round' pour etre plus precise

    while cents > 0:  # Ici je commence la tabulisation de la nombre de 'change' qui est presentement 0
        while cents >= 25:
            cents = cents - 25
            change = change + 1
        while cents >= 10:
            cents = cents - 10
            change = change + 1
        while cents >= 5:
            cents = cents - 5
            change = change + 1
        while cents >= 1:
            cents = cents - 1
            change = change + 1

    print(change)  # J'imprime le nombre de pieces de 'change' sur l'ecran pour l'utilisateur de voir


main()  # Je coupe le fonction principale