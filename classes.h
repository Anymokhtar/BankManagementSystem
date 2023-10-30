 #include<string>
 class compte;
 typedef struct  date {
    int j,m,a;
}date;
class client {
    private:
    std::string Cin;
    std::string nom;
    std::string prenom;
    std::string adresse;
    std::string ville;
    std::string tel ;
    public:
     client();
    std::string getCin();
    std::string getNom();
    std::string getPren();
    std::string getAders();
    std::string getVille();
    std::string getTel();
    void seAdresse(const std::string &);
    void setVille(const std::string&);
    void setTel(const std::string&);
   friend void ajout_client(client*,int);
    friend void ajout_compte(compte*,client*,int);
  friend int sup_comptclient(client*,std::string,int,compte*);
    void afficher_client (client*,std::string,int);
    void lister_client(client*, int);
   friend void recherche_cmpt(compte*,std::string,client*,int);
   friend void choixNumber_3(client*,int);
   void recherche(client*,int);
   friend void ajouterclient(client*,int);
   friend void chargerList_client(client*,int);
   client& operator=(const client&);

  };



class compte {
    private:
   std::string num_compte;
    float solde;
    std::string proprietaire;
    std::string mot_de_pass;
    date date_creation;
   std::string dern_opr;
    public:
    compte();
    compte& operator=(const compte &);
    std::string getNum_cmpt();
     float getSolde();
     std::string getProprietaire();
     int getJour();
     int getMois();
     int getAnne();
     friend void ajout_compte(compte*,client*,int);
    void setSolde(const float &);
    void setDrn_opr(const std::string &);
    void dernier_opr(compte*,int);
     void retrait_cmpt(compte*,int );
     void depose_cmpt(compte*,int);
   friend int sup_cmptclient(client*,std::string ,int ,compte*);
     void liste_cmpt(compte*,int);
     void afficher(std::string,compte*,int);
    friend void recherche_cmpt(compte*,std::string,client*,int);
    friend void ajoutercompte(compte*,int);
    friend void chargerList_compte(compte*,int);
};