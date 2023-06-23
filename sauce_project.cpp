#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

class Entity{
    public:
    int Attack, Defense, Speed, HP, BST, EntityNum;
    bool EquipStatus = 1;
    Entity(){
        Attack = rand()%100;
        Defense = rand()%100;
        Speed = rand()%100;
        HP = rand()%100;
        BST = Attack + Defense + Speed + HP + BST;
    }
};

int main(){
    Entity Equipped[6];
    string CatchVal;
    int EquippedSlots = 0;
    int StrongestSlot;
    Entity* StrongestSlotAddress;
    for(int i=0;i<6;i++){
        Equipped[i].EntityNum = i;
        Equipped[i].Attack = 0;
        Equipped[i].Defense = 0;
        Equipped[i].Speed = 0;
        Equipped[i].HP = 0;
        Equipped[i].BST = 0;
        Equipped[i].EquipStatus = 0;
    }

    Entity FodderEntity;

    int RandSeed = time(0);
    srand(RandSeed);
    while (Equipped[5].EquipStatus == false){
        Entity EncounterEntity;
        cout<<"An entity appears"<<endl;
        sleep(1);
        cout<<"It has a base stat total of "<<EncounterEntity.BST<<endl;
        sleep(1);
        cout<<"Do you want to catch it? You currently have "<<6-EquippedSlots<<" available spaces in your backpack"<<endl;
        sleep(0);
        cout<<"Answer Yes(Case Sensitive) for Yes or anything else for No: ";
        sleep(1);
        cin>>CatchVal;
        if (CatchVal == "Yes"){
            Equipped[EquippedSlots].Attack = EncounterEntity.Attack;
            Equipped[EquippedSlots].Defense = EncounterEntity.Defense;
            Equipped[EquippedSlots].Speed = EncounterEntity.Speed;
            Equipped[EquippedSlots].HP = EncounterEntity.HP;
            Equipped[EquippedSlots].BST = EncounterEntity.BST;
            Equipped[EquippedSlots].EquipStatus = EncounterEntity.EquipStatus;
            if (EquippedSlots == 0){
                StrongestSlotAddress = &Equipped[EquippedSlots];
                StrongestSlot = (*StrongestSlotAddress).EntityNum;
            }
            else if(Equipped[StrongestSlot].BST<Equipped[EquippedSlots].BST){
                StrongestSlotAddress = &Equipped[EquippedSlots];
                StrongestSlot = (*StrongestSlotAddress).EntityNum;
            }
            EquippedSlots++;
        }
        EncounterEntity.Attack = 0;
        EncounterEntity.Defense = 0;
        EncounterEntity.Speed = 0;
        EncounterEntity.HP = 0;
        EncounterEntity.BST = 0;
        EncounterEntity.EquipStatus = 0;
        if (Equipped[5].EquipStatus == true){
            sleep(1);
            cout<<"Your journey has come to and end"<<endl;
            sleep(1);
        }
        else{
            sleep(1);
            cout<<"Onto the next encounter"<<endl;
            sleep(1);
        }
    }

    cout<<"The most powerful entity in your backpack is Entity Number: "<<StrongestSlot+1<<endl<<"With a base stat total of: "<<(*StrongestSlotAddress).BST<<endl;
    cout<<"Attack:"<<(*StrongestSlotAddress).Attack<<endl;
    cout<<"Defense:"<<(*StrongestSlotAddress).Defense<<endl;
    cout<<"Speed:"<<(*StrongestSlotAddress).Speed<<endl;
    cout<<"HP:"<<(*StrongestSlotAddress).HP<<endl;
    cout<<"Average Stat: "<<(*StrongestSlotAddress).BST/4<<endl;
}