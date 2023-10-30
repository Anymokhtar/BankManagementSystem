#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<conio.h>
#include"classes.h"
using namespace std;
 void ChoixNumber_2(client*,int);
 void choixNumber_3(client*,int);
class compte;
 

 client::client(){
     Cin="";
     nom="";
     prenom="";
     adresse="";
     ville="";
     tel="";
 }
 //~~~~~~~~~~~~~~~~~~~~~~~~~~getter~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string client::getCin(){
     return Cin;
 }
string client::getNom(){
     return nom;
 }
 string client::getPren(){
     return prenom;
 }
 string client::getAders(){
     return adresse;
 }
  string client::getVille(){
     return ville;
 }
 string client::getTel(){
     return tel;
 }
//é~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~setter~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void client::setVille(const string &y){
    ville=y;
}

void client::seAdresse(const string &a){
     adresse=a;
}
void client::setTel(const string &r){
    tel=r;
}


 void client::afficher_client (client *l,string a ,int n){
 int j;
 for(j=0;j<n;j++){
     if((l+j)->Cin!=a){
                   cout<<"client n'existe pas";
                   break;
              }
else if((l+j)->Cin==a){
    cout<<"le nom est :" <<(l+j)->getNom()<<endl;
    cout<<"le prenom est :"<<(l+j)->getPren()<<endl;
    cout<<"le num telephone : "<<(l+j)->getTel()<<endl;
    cout<<"l'adresse est : "<<(l+j)->getAders()<<endl;
      break;
     }
    
      
     }
    
     }
     

 void client::lister_client (client *l,int n){
     int j;
     for(j=0;j<n;j++){
    cout<<"&~~~~~~~~~~~~client  "<<j+1<<" ~~~~~~~~~~~~& "<<endl;
    cout<<"le nom est :" <<(l+j)->getNom()<<endl;
    cout<<"le prenom est :"<<(l+j)->getPren()<<endl;
    cout<<"le num telephone : "<<(l+j)->getTel()<<endl;
    cout<<"l'adresse est : "<<(l+j)->getAders()<<endl;
      cout<<endl;
     }
 }
void client::recherche(client *t,int n){
    string x;
    int choix=-1;
    cout<<"entrer le cin de client que vous voullez chercher"<<endl;
    std::cin>>x;
    for(int i=0;i<n;i++){
         if((t+i)->Cin!=x){
cout<<"ce client n'existe pas";
break;

         }
        else if((t+i)->Cin==x){
        cout<<"Ce client est existe"<<endl;
        cout<<"Vous voullez afficher ces infos ? "<<endl<<"si oui tapez 1 si non tapez autre cles  "<<endl;
        cin>>choix;
          if(choix==1){
          cout<<endl;
          t->afficher_client(t,x,n); }
          else{
          system("pause");
          break;}
                         }
        
       
        

    } 
      
    }




compte::compte(){
    num_compte="";
    solde=0.00;
    proprietaire="";
    date_creation.j=01;
    date_creation.m=01;
    date_creation.a=2000;
    mot_de_pass="";
    dern_opr="Aucune Operation";
}

string compte::getNum_cmpt(){
    return num_compte;
}
string compte::getProprietaire(){
    return proprietaire;
}
float compte::getSolde(){
    return solde;
}
int compte::getJour(){
    return date_creation.j;
    }
    int compte::getMois(){
    return date_creation.m;
    }
    int compte::getAnne(){
    return date_creation.a;
    }

    void compte::setSolde(const float &d){
        solde=d;
    }
     void compte::setDrn_opr(const string &k){
       dern_opr =k;
    }
     void compte::retrait_cmpt(compte *t,int n){
         float s;
         string c,y;
         int j=0;
         y="retrait";

         cout<<"entrer votre mot de pass  ::  -->  ";
         cin>>c;
          float x;
           
         for( int i=0;i<n;i++){
          
                   
        
            if((t+i)->mot_de_pass==c){ 
                 
            cout<<"&~~~~~~~~~~~~entrer le montant que vous voullez retraiter~~~~~~~~~~~~&"<<endl;
            cin>>x;
            j=1;
             if(x<=(t+i)->solde){
            
          s=(t+i)->solde-x;
          this->setSolde(s);
          cout<<"operation effectuer avec succes";
         (t+i)->setDrn_opr(y);
         }
         else{
          cout<<"votre solde n'est pas suffisant pour effectuer cette operation";break;
         }
         }
             
        
         
         }  if(j==0){
                   cout<<"mot de pass incorect";
                   getch();}
                
              
        

         }

         void compte::depose_cmpt(compte *l,int n){
         float s,h;
         string c,y;
         int j=0;
         y="deposer";
         cout<<"entrer votre mot de pass :: --> ";
         cin>>c;
         for(int i=0;i<n;i++){
             
              if((l+i)->mot_de_pass==c){
             cout<<"&~~~~~~~~~~~~entrer le montant que vous voullez deposer~~~~~~~~~~~~~~~&"<<endl;
            cin>>h;
        
          s=(l+i)->solde+h;
          (l+i)->setSolde(s);
          cout<<"operation effectuer avec succes";
          (l+i)->setDrn_opr(y);
          j=1;
          
         
                        }
                       
            
              

              }
        if(j==0){
                   cout<<"mot de pass incorect";
                   getch();}
                       

        
         }
         void recherche_cmpt(compte *l,string c,client *t,int n){
             int choix=-1;
             for(int i=0;i<n;i++){
                //  if((l+i)->proprietaire!=c){
                //       cout<<"ce compte n'existe pas";
                //       break;

                //  }
                 
               if((l+i)->proprietaire==c){
                 cout<<"ce compte est existe//"<<endl;
                cout<<" vous voillez afficher ces infos ??? "<<endl<<"tapez 1 pour oui /autre pour non ";
                cin>>choix;
                 if(choix==1){
                     cout<<"&~~~~~~~~~~Infos sur compte~~~~~~~~~~&"<<endl;
                 cout<<"le num de compte est : "<<(l+i)->getNum_cmpt()<<endl;
                 cout<<"le cin du proprietaire est : "<<(l+i)->getProprietaire()<<endl;
                 cout<<"solde est :"<<(l+i)->getSolde()<<endl;
                 cout<<"date de creation :"<<(l+i)->getJour()<<"/"<<(l+i)->getMois()<<"/"<<(l+i)->getAnne()<<endl;
                 cout<<endl;
                 cout<<"&~~~~~~~~~Infos personel~~~~~~~~~&"<<endl;
                 for(int j=0;j<n;j++){
                     cout<<"le nom est :" <<(t+j)->getNom()<<endl;
                     cout<<"le prenom est :"<<(t+j)->getPren()<<endl;
                     cout<<"le num telephone : "<<(t+j)->getTel()<<endl;
                     cout<<"l'adresse est : "<<(t+j)->getAders()<<endl;

                 }
                 break;} 
                 else{ 
                 system("pause");
                 break;}
                     
                 }
                
                 
             }
            

         }
         void ajout_client(client *t,int n){
            ;
            // for( int i=0;i<n;i++){ 
         cout<<"&~~~~~~~~~~~infos client "<<n+1<<"~~~~~~~~~~~&"<<endl;
    cout<<"entrer votre cin -->";
    std::cin>>(t+n)->Cin;
    cout<<"entrer votre nom -->";
    std::cin>>(t+n)->nom;
    cout<<"entrer votre prenom -->";
    std::cin>>(t+n)->prenom;
    cout<<"entrer votre adresse -->";
    std::cin>>(t+n)->adresse;
    cout<<"entrer votre tel -->";
    std::cin>>(t+n)->tel;
    cout<<"entrer votre ville -->";
    std::cin>>(t+n)->ville;
    
}
         //}
        
        
    void ajout_compte(compte *l,client *t,int n){
       
cout<<"&~~~~~~~~~~~~a propos du compte"<<n+1<<"~~~~~~~~~~~~&"<<endl;   
      cout<<"entrer un numero de compte --->";
     cin>>(l+n)->num_compte;
     cout<<"entrer votre solde --->";
    cin>>(l+n)->solde;
     
     (l+n)->proprietaire=(t+n)->Cin;
      cout<<"le propritaire du compte est de cin :::"<<(l+n)->proprietaire<<endl;
      cout<<"entrer un mot de pass -->";
       cin>>(l+n)->mot_de_pass;
    //   for(char caractere = '0';getchar(caractere) != '\n' ;)
    //   cout<<"*";
     cout<<"entrer la date de creation "<<endl;
     do{
         cout<<"le jour est [1-31] --> ";
     cin>>(l+n)->date_creation.j;
     }while((l+n)->date_creation.j>31||(l+n)->date_creation.j<=0);
     do{
     cout<<"le mois est  [1-12] --> ";
     cin>>(l+n)->date_creation.m;
     }while((l+n)->date_creation.m>12||(l+n)->date_creation.m<=0);
     do{
     cout<<"l'annee est --> ";
     cin>>(l+n)->date_creation.a;
      }while((l+n)->date_creation.a<2000);

      

    }
 client& client::operator=(const client &t)
    {
        this->Cin = t.Cin;
        this->nom = t.nom;
        this->prenom = t.prenom;
        this->adresse = t.adresse;
        this->tel= t.tel;
        this->ville= t.ville;
       
    
        return *this;
    }
  compte& compte::operator=(const compte &l)
    {
        this->num_compte=l.num_compte;
        this->solde=l.solde;
        this->proprietaire=l.proprietaire;
        this->mot_de_pass=l.mot_de_pass;
        this->date_creation=l.date_creation;
        this->dern_opr=l.dern_opr;

        return *this;
    }



int sup_cmptclient(client *t,string c,int n,compte *l){
    int choix1=-1,choix2=-1;
    compte temp;
    client temp1;
    for(int i=0;i<n;i++){

        if((l+i)->proprietaire==c){
            cout<<"avez-vous vraiment suprime ce compte client ????  tapez 1 pour confirmer /autre cles pour affirmer  ::  -->  ";
            cin>>choix1;
           if(choix1==1){ 
              temp=*(l+i);
             for(int j=i;j<n-1;j++){
              *(l+j)=*(l+j+1);
              }
             cout<<"compte client de proprietaire : "<<c <<"  est supprime"<<endl;
             cout<<"voullez- vous suprime les donnees client  ??? tapez 1 pour confirmer /autre cles pour affirmer  :: -->  ";
            cin>>choix2;
             if(choix2==1){
                  temp1=*(t+i);
             for(int j=i;j<n-1;j++){
              *(t+j)=*(t+j+1);
              }
                cout<<"suppression avec succes";
                }
             
            else{
                system("pause");
                break;}
                
            }   
            else {
            system("pause");
                
            }
           
            }
        
            n--;

        }
        return n;
      }
         
          void compte::liste_cmpt(compte *l,int n){
              for(int i=0;i<n;i++){
                cout<<"&~~~~~~~~~~Infos du compte "<<i+1<<"~~~~~~~~~~&"<<endl;
                 cout<<"le num de compte est : "<<(l+i)->getNum_cmpt()<<endl;
                 cout<<"le cin du proprietaire est : "<<(l+i)->getProprietaire()<<endl;
                 cout<<"solde est :"<<(l+i)->getSolde()<<endl;
                 cout<<"date de creation :"<<(l+i)->getJour()<<"/"<<(l+i)->getMois()<<"/"<<(l+i)->getAnne()<<endl;
                 cout<<endl;
                
                 }}

          void compte::afficher(string c,compte *l,int n){
              int i;
              for(i=0;i<n;i++){
                //    if((l+i)->proprietaire!=c){
                //     cout<<"ce compte n'existe pas";
                //     break;
                //    }
                 if((l+i)->proprietaire==c){
                      
                 cout<<"&~~~~~~~~~~Infos sur compte~~~~~~~~~~&"<<endl;
                 cout<<"le num de compte est : "<<(l+i)->getNum_cmpt()<<endl;
                 cout<<"le cin du proprietaire est : "<<(l+i)->getProprietaire()<<endl;
                 cout<<"solde est :"<<(l+i)->getSolde()<<endl;
                 cout<<"date de creation :"<<(l+i)->getJour()<<"/"<<(l+i)->getMois()<<"/"<<(l+i)->getAnne()<<endl;
                 cout<<endl;
                
                 cout<<endl;
                 break;

                  }
                 
                  
              } 
             

          }
            void compte::dernier_opr(compte *t,int n){
                string x; int j=0;
                cout<<"entrer votre mot de pass  ::  -->  ";
                cin>>x;
                for(int i=0;i<n;i++){
                
                      
                    
                    
                 if((t+i)->mot_de_pass==x){
                        j=1;
                    cout<<"dernier operation effectuer dans ce compte est  "<<(t+i)->dern_opr;
                    break;}
                  
                        
                    
                 } 
                 if(j==0)
                  cout<<"&~~~~~~~~le mot de pass incorect~~~~~~~~~~&";
    
                    
                
                
            }

            

void ChoixNumber_2(client *t,int n){
    int choix;
    do{
        system("cls");
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
        cout<<"\t\t\t\t\t\t|*|~~~~~~~~~~~~~~~~~~~~~~~MENU Client~~~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[1]:~~~~~~~~~~~~~~~~~Recherche Client~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[2]:~~~~~~~~~~~~~~~~~~Lister client~~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[3]:~~~~~~~~~~~~~~~~Modification Client~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[4]:~~~~~~~~~~~~~~~~~~Afficher client~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[5]:~~~~~~~~~~~~~~~~~~MENU D'ACCUEIL~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
    	cin>>choix;
        if(choix==1){
        	t->recherche(t,n);

        }
        else if(choix==2){
             t->lister_client (t,n);
 
        }
        else if(choix==3){
         choixNumber_3(t,n);
        

        }
         else if(choix==4){
             string p;
               cout<<"Entrer le cin du client que vous voulez afficher  ::  -->  ";
            cin>>p;
             t->afficher_client (t,p,n);

         }


        else if(choix==5){
           getch();
           break;

        }
        else{
            cout<<"\t\t\t\t\t\t|*|~~~~~~Choix errone veuillez entrer une valeur entre 1 et 4~~~~~|*|"<<endl;


        }
getch();

    }while(choix!=4);

}


             

void choixNumber_3(client *t,int n){
    int choix=-1;
    do{
        system("cls");
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
        cout<<"\t\t\t\t\t\t|*|~~~~~~~~~~~~~~~~~~~~~MODIFICATION~~~~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[1]:~~~~~~~~~~~~~~Modification Par Ville~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[2]:~~~~~~~~~~~~~~Modification Par Tele~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[3]:~~~~~~~~~~~~~~Modification Par Adresse~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|*|[4]:~~~~~~~~~~~~~~~~~~MENU PRECEDENT~~~~~~~~~~~~~~~~~|*|"<<endl;
        cout<<"\t\t\t\t\t\t|=|=====================================================|=|"<<endl;
        cin>>choix;
        if(choix==1){
            string q,d;
            int j=0;
             cout<<"Entrer cin du proprietaire :: --> ";
             cin>>q;
            for(int i=0;i<n;i++){
               if((t+i)->Cin==q){
                   j=1;
             cout<<"Entrer la nouvelle ville : -->  "<<endl;
            cin>>d;
            t->setVille(d);
            cout<<"la ville a etait modifie";
            getch();}
        
           
            }
          if(j==0){
         cout<<"aucun compte client avec ce cin";
         getch();}
            }


        else if(choix==2){
             string h,g;
             int j=0;
            cout<<"Entrer cin du proprietaire :: --> ";
             cin>>g;
            for(int i=0;i<n;i++){
               if((t+i)->Cin==g){
                   j=1;
             cout<<"Entrer le nouveau numero de telephone: -->  "<<endl;
            cin>>h;
            t->setTel(h);
            cout<<"le numero de tele a etait modifie";
            getch();}
           
           
        }  if(j==0){
         cout<<"aucun compte client avec ce cin";
         getch();}
            

        }
        else if(choix==3){
             string o,w;
             int j=0;
            cout<<"Entrer cin du proprietaire :: --> ";
             cin>>w;
            for(int i=0;i<n;i++){
               if((t+i)->Cin==w){
                   j=1;
             cout<<"Entrer la nouvelle adresse: -->  "<<endl;
            cin>>o;
            t->seAdresse(o);
            cout<<"l'adresse a etait modifie";
            getch();}
           
            
        }
        if(j==0){
          cout<<"aucun compte client avec ce cin";getch(); }
        }
        else if(choix==4){
            
            getch();
        }
        else{
            cout<<"\t\t\t\t\t\t|*|~~~~~~Choix errone veuillez entrer une valeur entre 1 et 4~~~~~|*|"<<endl;
        }

    }while(choix!=4);
}
     void ajouterclient(client *t,int n)
{
    fstream fout;
    fout.open("client.txt", ios::out);

    for(int k=0;k<n;k++)
    {
        
     fout <<(t+k)->Cin<< ","
             <<(t+k)->nom << ","
             <<(t+k)->prenom<< ","
             <<(t+k)->adresse<<","
             <<(t+k)->ville<<","
             <<(t+k)->tel<<","; 
    }
    fout<<"\n";
    fout.close();}

     void ajoutercompte(compte *l,int n)
{
    fstream fout;
    fout.open("compte.txt",ios::out);

        for (int i=0;i<n;i++)
        {
        
            fout <<(l+i)->num_compte<< ","
                 <<(l+i)->solde<<" , "
                 <<(l+i)->proprietaire<< " , "
                 <<(l+i)->mot_de_pass<<" , "
                 <<(l+i)->date_creation.j<<"/"
                 <<(l+i)->date_creation.m<<"/"
                 <<(l+i)->date_creation.a<<" , "
                 <<(l+i)->dern_opr;
        }
        fout << "\n";
    
    fout.close();
}
