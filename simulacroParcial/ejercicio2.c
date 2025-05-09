#include <stdio.h>

void ataqueEnemigo(int mana);

int main(){
    int mana = 0;
    int damageTotal;
    do
    {
        printf("\n Ingrese el mana del enemigo: ");
        scanf("%d", &mana);
        if (mana<120 || mana>300)
        {
            printf("Esta ingresando un mana incorrecto.");
        }
        
    } while (mana<120 || mana>300);
    
    ataqueEnemigo(mana);

    return 0;
}

void ataqueEnemigo(int mana){
    int damage;
    damage = (40) + (int)(mana * 0.15);
    if (damage > 80)
    {
        printf("\n CRITICAL HIT \n Damage: %d", damage);
    }
    else
    {
        printf("\n NORMAL HIT \n Damage: %d", damage);
    }
    

}