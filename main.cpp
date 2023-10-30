#include<cstdio>
#include<iostream>
#include<string>
#include"projet.cpp"
#include<conio.h>
#include<stdlib.h>


int main(){

    int choix=-1;
     int n=0,i;
    client *t=new client[100];
    compte *l=new compte[100];
    do{
        system("cls");
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
        cout<<"\t\t\t\t\t\t|*|~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[1]:~~~~~~~~~~~~~~Cree un Compte Client~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[2]:~~~~~~~~~~~~~~~~~~Gestion Clients~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[3]:~~~~~~~~~~~~~~~~Depot d'un Montant~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[4]:~~~~~~~~~~~~~~~Retrait d'un Montant~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[5]:~~~~~~~~~~~~Afficher Dernier Operation~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[6]:~~~~~~~~~~~~~~Suprimer Compte Client~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[7]:~~~~~~~~~~~~~~~~Lister Les comptes~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[8]:~~~~~~~~~~~~~~~~Afficher Un Compte~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[9]:~~~~~~~~~~~~Recherche Un compte Client~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[10]:~~~~~~~~~~~~~~~~~Pour Quitter~~~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
        
    	cin>>choix; 
       if(choix==1){
          //cout<<"entrer le nbmr de compte que vous voulez saisir"<<endl;
          //cin>>n;
             
            ajout_client(t,n);
            
            ajout_compte(l,t,n);
            n++;

            cout<<"\t\t\t\t\t\t&~~~~~~~~le compte a etait creer avec succes~~~~~~~~~&";
           }
        
        
        else if(choix==2){
           ChoixNumber_2(t,n);

        }
        else if(choix==3){
          
           l->depose_cmpt(l,n);
        }
        else if(choix==4){
           

            l->retrait_cmpt(l,n);
        
            
        }
        else if(choix==5){
            l->dernier_opr(l,n);
            
        }
        else if(choix==6){
            string c;
            cout<<"Entrer le cin de compte client que vous voulez suprimer  ::  -->  ";
            cin>>c;
            n=sup_cmptclient(t,c,n,l);

        }
        else if(choix==7){
    
           l->liste_cmpt(l,n);
          
        }
        else if(choix==8){
            string k;
             cout<<"Entrer le cin de compte client que vous voulez afficher  ::  -->  ";
            cin>>k;
           l->afficher(k,l,n);
        }
        else if(choix==9){
            string v;
            cout<<"Entrer le cin du proprietaire que vous voulez chercher : -->  ";
            cin>>v;
            recherche_cmpt(l,v,t,n);
        }
        else if(choix==10){
            int choiq;
            cout<<"\t\t\t\t\t\t|*|~~~~~~~Vous voulez vraiment quitter ? 1 pour oui et autre pour non~~~~|*|"<<endl;
            cin>>choiq;
            if(choiq==1){
                 ajouterclient(t,n);
                ajoutercompte(l,n);
                system("pause");
                system("cls");

            }
            else 
                choix=-1;
            
        }
        else{
            cout<<"\t\t\t\t\t\t|*|~~~~~~~~Choix errone veuillez entrer une valeur entre 1 et 10~~~~~~~|*|"<<endl;
        }
    
getch();

    }while(choix!=10);


   
    return 0;
}


