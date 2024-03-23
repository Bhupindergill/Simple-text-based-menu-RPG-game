/* RPG Game
   Bhupinder Gill
*/

#include <iostream>
using namespace std;
int main(){
   // 
   int level = 1;
   int exp = 0;
   int totalexp = 0;
   int total_money = 0;   
   int health = 10;
   int total = 10;
   int max = 10;
   int attack = 7;
   int defense = 2;
   int special = 5;
   bool exit = false;
   int potion = 0;
   bool armor[3];
   bool weapon[4];
   bool magic[3];
   armor[0] = false; // wood armor
   armor[1] = false; // steel armor
   armor[2] = false; // dragon armor
   weapon[0] = false; // wood sword
   weapon[1] = false; // steel sword
   weapon[2] = false; // diomand sword
   weapon[3] = false; // dragon sword
   magic[0] = false; // magic lv.1
   magic[1] = false; // magic lv.2
   magic[2] = false; // magic lv.3
   do
   { 
    //enemy variables
    string enemy_name[3];
    int enemy_health[3];
    int total_health[3];
    int enemy_attack[3];
    int enemy_def[3];
    int enemy_special[3];
    int enemy_exp[3];
    int level_id[3];
    //
    int user_choice = 0;
    int loop = 0;
    int etotal[3];
    int atotal;
    int eatotal;
    bool gameover = false; 
    bool shop = false;
    //Player varables 
    //-- 
    // enemy
    enemy_name[0] = "a Bat";
    enemy_health[0] = 5;
    etotal[0] = 5;
    enemy_attack[0] = 3;
    enemy_def[0] = 1;
    enemy_special[0] = 0;
    enemy_exp[0] = 35;
    level_id[0] = 1;
    //
    enemy_name[1] = "a Skeleton";
    enemy_health[1] = 7;
    etotal[1] = 7;
    enemy_attack[1] = 6;
    enemy_def[1] = 4;
    enemy_special[1] = 1;
    enemy_exp[1] = 20;
    level_id[1] = 2;
    // 1st boss
    enemy_name[2] = "the First Boss: Bird King";
    enemy_health[2] = 20;
    etotal[2] = 20;
    enemy_attack[2] = 10;
    enemy_def[2] = 7;
    enemy_special[2] = 5;
    enemy_exp[2] = 100;
    level_id[2] = 3;
    //
               
                
                
                
                
                
                
                  
    cout << "*****Menu*****\n" << "1) Battle\n" << "2) Shop\n" << "3) Inn\n" << "4) Exit\n\n";
    cout << "Level   = " << level << "\nMoney   = $" << total_money << "\nHealth  = " << total << "\nAtk     = " << attack << "\nDef     = " << defense << "\nSpecial = " << special << "\nExp     = " << totalexp << endl;
    cin >> user_choice;
    if (user_choice == 1)
    {
     for(int i = 0; i < 3; i++) 
     { 
             if(loop == 1)
             {
                     i++;
             }
             (i-1);
                if (level == level_id[i])
                {
                       do
                       {
                       cout << "You are battling " << enemy_name[i] << "!\n\nHealth = " << etotal[i]<< "\n";
                       cout << "Your health = " << total << "\n\n" << " 1)Attack\n 2)Magic\n 3)Potion\n\n";
                       cin >> user_choice;
                       if (user_choice == 1)
                       {
                                  atotal = attack - enemy_def[i];
                                  etotal[i] -= /*enemy_health[i] -*/ atotal;
                                  cout << "You did " << atotal << " damage!\n";
                                  if (etotal[i] < 1)
                                  {
                                                    gameover = true;
                                                    cout << "You defeated " << enemy_name[i] << "!\n\n";
                                  }
                                  else if (gameover == false)
                                  {
                                       eatotal = enemy_attack[i] - defense;
                                       total -= /*health -*/ eatotal;
                                       cout << "You took " << eatotal << "!\n";
                                       if (total <= 0)
                                       {
                                                  gameover = true;
                                                  cout << "You have lost!\n";
                                       }
                                  }
                       }
                       else if (user_choice == 3)
                       {
                            if (potion > 0)
                            {
                                       potion--;
                                       cout << "You used a potion and recovered 10 HP\n" << "You now have " << potion << " potions left.\n\n";
                                       total += 10;
                                       if (total > max)
                                       {
                                                 total = max;
                                       }
                                       eatotal = enemy_attack[i] - defense;
                                       total -= /*health -*/ eatotal;
                                       cout << "You took " << eatotal << "!\n";
                                       if (total <= 0)
                                       {
                                                  gameover = true;
                                                  cout << "You have lost!\n";
                                       }
                            }
                            else
                            {
                                cout << "You don't have any potions.\n\n";
                            }
                       }           
                       } while (gameover != true);
                       if (etotal[i] <= 0)
                       {
                                     if(totalexp == 0)
                                     {
                                        totalexp = exp + enemy_exp[i];
                                     }
                                     else
                                     {
                                         int temp[2];
                                         temp[0] = totalexp;
                                         totalexp = exp + enemy_exp[i];
                                         temp[1] = totalexp + temp[0];
                                         totalexp = temp[1];
                                     }
                                     cout << "You have in total of " << totalexp << " EXP!\n";
                                        if (totalexp >= 100)
                                        {
                                                level++;
                                                exp = 0;
                                                totalexp = 0;
                                                health++;
                                                health++;
                                                total++;
                                                total++;
                                                max++;
                                                max++;
                                                attack++;
                                                attack++;
                                                atotal++;
                                                atotal++;
                                                defense++;
                                                defense++;
                                                special++;
                                                special++;
                                                cout << "You are now level " << level << "!\n\n";
                                        }
                                        total_money += 20;
                                        cout << "You got $20!\n" << "You now have $" << total_money << "!\n\n";
                                        loop++;                           
                       }
                       else
                       {
                          exit = true;
                          loop++;
                       }
                        
                }
     }
                    
    } 
    else if (user_choice == 2)
    {
         do
         {
          system("cls");
          cout << "*****Welcome to the shop*****   Money = $" << total_money << "\n\n";
          cout << "1) Potion (recovers 10 HP)..... $20\n"
               << "5) Exit\n";
          cin >> user_choice;
          if (user_choice == 1)
          {
                         if (total_money >= 20)
                         {
                                         
                                         cout << "You baught a potion!\n";
                                         total_money -= 20;
                                         potion++;
                         }
                         else
                         {
                             cout << "You don't have enough cash.\n";
                         }
          }
          else if (user_choice == 5)
          {
               shop = true;
               cout << "Please come again!\nPress Enter to Continue...\n";
          }
          cin.ignore();
          cin.get();
         } while (shop != true);
    }
    else if (user_choice == 3)
    {
         if(total_money >= 50)
         {
                        cout << "Welcome to the town INN, it will cost $50 for one night.\n" << "Press Enter to Continue...\n";
                        cin.ignore();
                        cin.get();
                        total_money -= 50;
                        total = max;
                        cout << "You are now rested and your health has been restored!\n";
         }
         else
         {
             cout << "Sorry, you don't have enough money.\n";
         }
    }
    else if (user_choice == 4)
    {
         exit = true;
    }
    cout << "Press Enter to Continue...\n";
    cin.ignore();
    cin.get();
    system("cls");
    } while (exit != true);
        
 return 0;
}
