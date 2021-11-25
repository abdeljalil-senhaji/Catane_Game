#include "mini_projet.h"
#include <iostream>

using namespace std;


/*************************************************************************
**************************/
string alies;  //variable globale pour stocker alies 

ExampleWindow::ExampleWindow() //
{
    std::ifstream file("VampireV5.txt");  //ouverture du fichier VampireV5 qui contient toutes les informations
    string str= "# Clans"; // string recherchée
    string str2= "--"; //string recher recherchée
    vector<string> all;  //stockage des information sous forme de vecteur

    while (std::getline(file, str) ) //tant qu'on recupére la ligne contenant le string str ("# Clan")
    {
        if (str.find(str2) != std::string::npos)  //si dans le string recupéré il y'a le string str2 ("--")
        {

            all.push_back(str); //on stocke dans le vecteur all 
        }

    }
    file.close(); //on ferme le fichier
        set_title("Vampire Interface"); //titre de l'interface
        set_border_width(5);
        set_position(Gtk::WIN_POS_CENTER);
        resize(400, 200); 
    // Définition du style des grids ==> on leur donne toutes une couleur de background noire 
        mainGrid1.override_background_color (	Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL );
        mainGrid2.override_background_color (	Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL );
        mainGrid3.override_background_color (	Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL );
        mainGrid4.override_background_color (	Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL );
    // Définition du style des labels ==> on donne au texte la couleur blanche 
        m_Label_2.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); m_Label_3.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_4.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_5.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); 
        m_Label_6.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); m_Label_7.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_8.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); m_Label_9.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_10.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); m_Label_11.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_12.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_13.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_14.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL); m_Label_15.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_16.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_17.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_18.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);   m_Label_19.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_20.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_21.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_22.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_23.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_24.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_25.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_26.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_27.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_28.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_29.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_30.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_31.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_31.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_32.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_33.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_34.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_35.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_36.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_37.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_38.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_41.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_40.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_42.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_43.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_44.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_45.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_46.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);m_Label_47.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        m_Label_48.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
        
        //Définition du label Clan et du combobox contenant tout les clans
        m_Label_3.set_markup(" <b> Clan </b>");
        m_Label_3.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_3, 5, 0, 5, 1);

        vector<string>::iterator it; //iterator
        //remplir combobox avec contenue du fichier 
        for (it=all.begin()+72; it<all.begin()+78; it++) //iteration
        alies=*it; //remplir alies 
        for (it=all.begin(); it<all.begin()+30; it++) //iteration
        c.append(*it); //remplir les clans
        mainGrid1.attach(c, 5,3,5,1); //attacher le combobox à la grille

        //label nature et combobox nature
        m_Label_4.set_markup("<b> Nature </b>");
        m_Label_4.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_4, 5, 7, 5, 2);
        for (it=all.begin()+30; it<all.begin()+30+42; it++) //iteration
        nature.append(*it);
        mainGrid1.attach(nature, 5,9,5,1);

        //label de le la zone de texte des pts attributs social
        m_Label_19.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_19.set_markup("<b> Pts attiributs social (1) </b>");
        mainGrid1.attach(m_Label_19, 15, 35, 2, 2);
        inputEntry1.set_text("0");
        mainGrid1.attach(inputEntry1, 15, 40, 2,1);

        //attributs social
        m_Label_7.set_markup("<b> Social Attributes (1) </b>"); //label
        m_Label_7.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_7, 0, 35, 2, 2);

        for (it=all.begin()+75; it<all.begin()+78; it++) //iteration
        attribute_social.append(*it);                    //remplir combobox directement à partir du fichier
        mainGrid1.attach(attribute_social, 0,40,2,1);

        m_Label_20.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_20.set_markup("<b> Pts attiributs mental </b>");
        mainGrid1.attach(m_Label_20, 15, 25, 2, 2);

        inputEntry2.set_text("0");
        mainGrid1.attach(inputEntry2, 15, 30, 2,1);


        m_Label_8.set_markup(" <b> Mental Attributes (1)</b>");
        m_Label_8.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_8, 0, 25, 2, 2);

        for (it=all.begin()+78; it<all.begin()+81; it++) // iteration
        attribute_mental.append(*it);
        mainGrid1.attach(attribute_mental, 0, 30 ,2,1);


        m_Label_21.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_21.set_markup("<b> Pts attiributs physical (1)</b>");
        mainGrid1.attach(m_Label_21, 15, 12, 2, 2);
        
        inputEntry3.set_text("0");
        mainGrid1.attach(inputEntry3, 15, 15, 2,1);

        m_Label_6.set_markup("<b> Physical Attributes (1)</b>");
        m_Label_6.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_6, 0, 12, 2, 2);

        for (it=all.begin()+72; it<all.begin()+75; it++) //iteration
        attribute_physical.append(*it);
        mainGrid1.attach(attribute_physical, 0,15,2,1);


        m_Label_44.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_44.set_markup("<b> Pts attiributs social (2) </b>");
        mainGrid1.attach(m_Label_44, 15, 50, 2, 2);

        social2.set_text("0");
        mainGrid1.attach(social2, 15, 55, 2,1);

        m_Label_29.set_markup("<b> Social Attributes (2) </b>");
        m_Label_29.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_29, 0, 50, 2, 2);

        for (it=all.begin()+75; it<all.begin()+78; it++) //iteration
        attribute_social1.append(*it);
        mainGrid1.attach(attribute_social1, 0,55,2,1);

        m_Label_45.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_45.set_markup("<b> Pts attiributs social (3) </b>");
        mainGrid1.attach(m_Label_45, 15, 60, 2, 2);

        social3.set_text("0");
        mainGrid1.attach(social3, 15, 65, 2,1);

        m_Label_46.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_46.set_markup("<b> Pts attiributs physical (2) </b>");
        mainGrid1.attach(m_Label_46, 15, 18, 2, 2);

        physical2.set_text("0");
        mainGrid1.attach(physical2, 15, 20, 2,1);



        m_Label_28.set_markup("<b> Physical Attributes (2)</b>");
        m_Label_28.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_28, 0, 18, 2, 2);

        for (it=all.begin()+72; it<all.begin()+75; it++) //iteration
        attribute_physical1.append(*it);
        mainGrid1.attach(attribute_physical1, 0,20,2,1);




        m_Label_41.set_markup("<b> Social Attributes (3) </b>");
        m_Label_41.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid1.attach(m_Label_41, 0, 60, 2, 2);

        for (it=all.begin()+75; it<all.begin()+78; it++) //iteration
        attribute_social2.append(*it);
        mainGrid1.attach(attribute_social2, 0,65,2,1);


///////////////////////////////////////////////////////////////////////////:// Abilities 
        m_Label_9.set_markup(" <b> Abilities - talents (1) </b>");
        m_Label_9.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid2.attach(m_Label_9, 5, 30, 2, 2);


        for (it=all.begin()+81; it<all.begin()+92; it++) //iteration
        abilities_talents.append(*it);
        mainGrid2.attach(abilities_talents, 5, 35, 2, 1);

        m_Label_22.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_22.set_markup("<b> Pts Abilities skills </b>");
        mainGrid2.attach(m_Label_22,  15, 10, 2, 2);

        inputEntry4.set_text("0");
        mainGrid2.attach(inputEntry4, 15, 15, 2,1);

        m_Label_23.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_23.set_markup("<b> Pts abilities knowledges </b>");
        mainGrid2.attach(m_Label_23, 15, 20, 2, 2);

        inputEntry5.set_text("0");
        mainGrid2.attach(inputEntry5, 15, 25, 2,1);

        m_Label_24.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_24.set_markup("<b> Pts abilities talents (1)</b>");
        mainGrid2.attach(m_Label_24, 15, 35, 2, 2);

        inputEntry6.set_text("0");
        mainGrid2.attach(inputEntry6, 15, 40, 2,1);

        m_Label_48.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_48.set_markup("<b> Pts abilities talents (2)</b>");
        mainGrid2.attach(m_Label_48, 15, 45, 2, 2);

        talent2.set_text("0");
        mainGrid2.attach(talent2, 15, 50, 2,1);

        m_Label_32.set_markup(" <b> Abilities - talents (2) </b>");
        m_Label_32.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid2.attach(m_Label_32, 5, 40, 2, 2);


        for (it=all.begin()+81; it<all.begin()+92; it++) //iteration
        abilities_talents1.append(*it);
        mainGrid2.attach(abilities_talents1, 5, 45, 2, 1);

        m_Label_10.set_markup(" <b> Abilities - Skills </b>");
        m_Label_10.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid2.attach(m_Label_10, 5, 5, 2, 2);

        for (it=all.begin()+92; it<all.begin()+103; it++) //iteration
        abilities_skills.append(*it);
        mainGrid2.attach(abilities_skills, 5, 10, 2, 1);


        m_Label_11.set_markup(" <b> Abilities - Knowledges </b>");
        m_Label_11.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid2.attach(m_Label_11, 5, 15, 2, 2);

        for (it=all.begin()+103; it<all.begin()+114; it++) //iteration
        abilities_knowledges.append(*it);
        mainGrid2.attach(abilities_knowledges, 5, 20, 2, 1);

/////////////////////////////////////////////////////////////////// Advantages
        advantages.set_markup(" Advantages ");
        mainGrid3.attach(advantages, 10, 0, 6, 2);

        m_Label_12.set_markup(" <b> Advantages - disciplines </b>");
        m_Label_12.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid3.attach(m_Label_12, 5, 5, 2, 2);

        for (it=all.begin()+114; it<all.begin()+121; it++) //iteration
        advantages_disciplines.append(*it);
        mainGrid3.attach(advantages_disciplines, 5, 10, 2, 1);

        m_Label_13.set_markup("<b> Advantages - Backgrounds </b>");
        m_Label_13.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid3.attach(m_Label_13, 5, 20, 2, 2);

        for (it=all.begin()+121; it<all.begin()+128; it++) //iteration
        advantages_backgrounds.append(*it);
        mainGrid3.attach(advantages_backgrounds, 5, 25, 2, 1);

        m_Label_14.set_markup("<b> Advantages - virtues (1) </b>");
        m_Label_14.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid3.attach(m_Label_14, 5, 30, 2, 2);

        for (it=all.begin()+128; it<all.begin()+132; it++) //iteration
        advantages_virtues.append(*it);
        mainGrid3.attach(advantages_virtues, 5, 35, 2, 1);

        m_Label_30.set_markup("<b> Advantages - virtues (2) </b>");
        m_Label_30.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid3.attach(m_Label_30, 5, 40, 2, 2);

        for (it=all.begin()+128; it<all.begin()+132; it++) //iteration
        advantages_virtues1.append(*it);
        mainGrid3.attach(advantages_virtues1, 5, 45, 2, 1);

        m_Label_25.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_25.set_markup("<b> Pts Advantages disciplines</b>");
        mainGrid3.attach(m_Label_25, 20, 20, 2, 2);

        inputEntry7.set_text("0");
        mainGrid3.attach(inputEntry7, 20, 25, 2,1);

        m_Label_26.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_26.set_markup("<b> Pts advantages backgrounds </b>");
        mainGrid3.attach(m_Label_26, 20, 5, 2, 2);

        inputEntry8.set_text("0");
        mainGrid3.attach(inputEntry8, 20, 10, 2,1);

        m_Label_27.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_27.set_markup("<b> Pts advantages virtues (1)</b>");
        mainGrid3.attach(m_Label_27, 20, 30, 2, 2);

        inputEntry9.set_text("0");
        mainGrid3.attach(inputEntry9, 20, 35, 2,1);

        m_Label_47.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_47.set_markup("<b> Pts advantages virtues (2)</b>");
        mainGrid3.attach(m_Label_47, 20, 40, 2, 2);

        virtues2.set_text("0");
        mainGrid3.attach(virtues2, 20, 45, 2,1);

//////////////////////////////////////////////////////////////////////Merits and Flows
        m_Label_15.set_markup(" <b> Merits and Flows - Physical (1) </b>");
        m_Label_15.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_15, 5, 5, 2, 2);

        for (it=all.begin()+205; it<all.begin()+247; it++) //iteration
        MertisFlows_physical.append(*it);
        mainGrid4.attach(MertisFlows_physical, 5, 10, 2, 1);

        m_Label_33.set_markup(" <b> Merits and Flows - Physical(2) </b>");
        m_Label_33.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_33, 5, 15, 2, 2);

        for (it=all.begin()+205; it<all.begin()+247; it++) //iteration
        MertisFlows_physical1.append(*it);
        mainGrid4.attach(MertisFlows_physical1, 5, 20, 2, 1);

        m_Label_17.set_markup(" <b> Merits and Flows - Mental (1)</b>"); //(2)  18-22
        m_Label_17.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_17, 5, 25, 2, 2);
        
        for (it=all.begin()+247; it<all.begin()+283; it++) //iteration
        MeritsFlows_mental.append(*it);
        mainGrid4.attach(MeritsFlows_mental, 5, 30, 2, 1);

        m_Label_34.set_markup(" <b> Merits and Flows - Mental (2)</b>"); //(2)  18-22
        m_Label_34.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_34, 5, 35, 2, 2);
        
        for (it=all.begin()+247; it<all.begin()+283; it++) //iteration
        MeritsFlows_mental1.append(*it);
        mainGrid4.attach(MeritsFlows_mental1, 5, 40, 2, 1);

        m_Label_16.set_markup(" <b> Merits and Flows - Social (1) </b>");
        m_Label_16.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_16, 15, 5, 2, 2);


        for (it=all.begin()+283; it<all.begin()+339; it++) //iteration
        MeritsFlows_social.append(*it);
        mainGrid4.attach(MeritsFlows_social, 15, 10, 2, 1);

        m_Label_35.set_markup(" <b> Merits and Flows - Social (2)</b>");
        m_Label_35.set_alignment(Gtk::ALIGN_CENTER);
        mainGrid4.attach(m_Label_35, 15, 15, 2, 2);

        for (it=all.begin()+283; it<all.begin()+339; it++) //iteration
        MeritsFlows_social1.append(*it);
        mainGrid4.attach(MeritsFlows_social1, 15, 20, 2, 1);

        m_Label_18.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_18.set_markup("<b> Merits and Flows - Supernatural (1) </b>");
        mainGrid4.attach(m_Label_18, 15, 25, 2, 2);

        for (it=all.begin()+339; it<all.end(); it++) //iteration
        MeritsFlows_supernatural.append(*it);
        mainGrid4.attach(MeritsFlows_supernatural, 15, 30, 2, 1);

        m_Label_40.set_alignment(Gtk::ALIGN_CENTER);
        m_Label_40.set_markup("<b> Merits and Flows - Supernatural (2) </b>");
        mainGrid4.attach(m_Label_40, 15,  35, 2, 2);

        for (it=all.begin()+339; it<all.end(); it++) //iteration
        MeritsFlows_supernatural1.append(*it);
        mainGrid4.attach(MeritsFlows_supernatural1, 15, 40, 2, 1);
        
////////// les bouttons ///////////

        submit_button.add_label("Valider le personnage"); //bouton de validation
        submit_button.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::GetAllValues));
        mainGrid4.attach(submit_button, 10, 55, 5, 1);
        //boutton d'affichage des formulaires
        m_button.add_pixlabel("info.xpm", "Afficher les formulaires");
        mainGrid4.attach(m_button, 10, 65,5,2);
        m_button.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::on_button_clicked));
       //on attaches les grids au notebook pour avoir des onglets 
        Selector.append_page(mainGrid1, "Attributs");
        Selector.append_page(mainGrid2, "Abilities");
        Selector.append_page(mainGrid3, "Advantages");
        Selector.append_page(mainGrid4, "Merits and Flows");
        //ajout du note book à la fenetre 
        add(Selector);
        show_all_children();
}

ExampleWindow::~ExampleWindow() //destructeur
{
}
//variables globales qui facilite la récupération des informations entre les différentes classes 
string name, nickN, nat, phy, phy2,ment, social1,social23, social33,know, talent11,talent22, MF_socia,
 MF_ment, SuperN, MF_phy, Skills, dis,back, MF_ment2, MF_phy2, MF_socia2, SuperN2;
int sum_physical1=0, sum_physical2=0, sum_mental=0,  sum_skills=0, sum_knowledges=0, sum_talent1=0, 
sum_talent2=0, sum_social1=0, sum_social2=0, sum_social3=0,sum_disciplines=0, sum_backgrounds=0;

/***********************************************************************************************************************/

void ExampleWindow::GetAllValues() //fonction qui récuprère toute les valeurs choisies/saisies par l'utilisateur 
{ 
    int id; 
    // Récupération de toutes les valeurs de tous les combobox 
    name=c.get_active_text ();
    nat=nature.get_active_text();
    phy=attribute_physical.get_active_text();
    phy2=attribute_physical1.get_active_text();
    ment= attribute_mental.get_active_text();
    social1= attribute_social.get_active_text();
    Skills= abilities_skills.get_active_text();
    social23= attribute_social1.get_active_text();
    social33= attribute_social2.get_active_text();
    know=abilities_knowledges.get_active_text();
    talent11 = abilities_talents.get_active_text();
    talent22= abilities_talents1.get_active_text();
    dis= advantages_disciplines.get_active_text();
    back= advantages_backgrounds.get_active_text();
    MF_socia= MeritsFlows_social.get_active_text();
    MF_ment= MeritsFlows_mental.get_active_text();
    SuperN= MeritsFlows_supernatural.get_active_text();
    MF_phy= MertisFlows_physical.get_active_text();
    MF_socia2= MeritsFlows_social1.get_active_text();
    MF_ment2= MeritsFlows_mental1.get_active_text();
    SuperN2= MeritsFlows_supernatural1.get_active_text();
    MF_phy2= MertisFlows_physical1.get_active_text();

    int cp=0; //compteur de controle des valeurs saisies 

    int sum_social,  sum_physical;
    sum_social = stoi(inputEntry1.get_text())+  stoi(social2.get_text())+ stoi(social3.get_text());
    sum_social1 = stoi(inputEntry1.get_text());
    sum_social2=  stoi(social2.get_text());
    sum_social3= stoi(social3.get_text());

    sum_mental = stoi(inputEntry2.get_text()) ;
    sum_physical= stoi(inputEntry3.get_text()) + stoi(physical2.get_text());;
    sum_physical1= stoi(inputEntry3.get_text()) ;
    sum_physical2= stoi(physical2.get_text());
    if (cp==0)
    { 
                if( sum_mental+sum_social+sum_physical >15 ) //verifier que tous les points attribués respectent la condition
                {
                    Gtk::MessageDialog dialog(*this, "Warning");    //pop-up qui s'affiche si la condition n'est pas respectée
                    dialog.set_secondary_text(
                    "The total number of points in attributes has to be <= 15");
                    dialog.run();
                    cp++;
                }

                int sum_talents;
                sum_skills = stoi(inputEntry4.get_text());
                sum_knowledges = stoi(inputEntry5.get_text());
                sum_talents= stoi(inputEntry6.get_text())+stoi(talent2.get_text());
                sum_talent1= stoi(inputEntry6.get_text());
                sum_talent2= stoi(talent2.get_text());


                if( sum_skills+sum_knowledges+sum_talents > 27)
                {
                    Gtk::MessageDialog dialogue(*this, "Warning");
                    dialogue.set_secondary_text(
                    "The total number of points in attributes has to be <= 27");
                    dialogue.run();
                    cp++;
                }

                int  sum_virtues;
                sum_disciplines = stoi(inputEntry7.get_text());
                sum_backgrounds = stoi(inputEntry8.get_text());
                sum_virtues= stoi(inputEntry9.get_text())+stoi(virtues2.get_text());

                if( sum_disciplines > 3)
                {
                    Gtk::MessageDialog dialogue(*this, "Warning");
                    dialogue.set_secondary_text(
                    "The total number of points in discipline has to be <= 3");
                    dialogue.run();
                    cp++;
                }


                if( sum_virtues > 5)
                {
                    Gtk::MessageDialog dialogue(*this, "Warning");
                    dialogue.set_secondary_text(
                    "The total number of points in virtues has to be <= 5");
                    dialogue.run();
                    cp++;
                }

                if( sum_backgrounds > 7)
                {
                    Gtk::MessageDialog dialogue(*this, "Warning");
                    dialogue.set_secondary_text(
                    "The total number of points in backgrounds has to be <= 7");
                    dialogue.run();
                    cp++;

                }
        //si tout est bon on informe l'utilisateur que les info ont été validées
        Gtk::MessageDialog dialogue(*this, "Information");
        dialogue.set_secondary_text(
                    "your personnage has been saved");
        dialogue.run();
    }
}
/*************************************************************************************
*******************************$*******************************************************************/
void ExampleWindow::on_button_clicked() // fonction appelée lors du click, elle afficher les 4 pages remplies
{
  //  std::cout << "The Button was clicked." << std::endl; //confirmer que la fonction est appelée lors du click
    //affichage de la page 4 dans une nouvelle fenetre
    Gtk::Window *p4 = new Gtk::Window();
    //ajout de la page dans la fenetre
    p4->add(page4);
    //tout afficher 
    p4 ->show_all();
    // affichage de la page 3
    Gtk::Window *p3 = new Gtk::Window();
    p3->add(page3); //ajout de la page
    p3 ->show_all(); //tout afficher
    //affichage de la page 2
    Gtk::Window *ex = new Gtk::Window();
    ex->add(page2);  // ajout de la page dans la fenetre 
    ex ->show_all();
    //ouverture de la page 1
    Gtk::Window *exw = new Gtk::Window(); //creation de la nouvelle fenetre
    //ajout de la page dans le box
    VBox1.pack_start(dessin);
    Gtk::Button button;
    button.add_label("export to pdf");
    button.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::export_to_pdf));
    VBox1.pack_end(button);
    //ajout du box dans la fenetre
    exw->add(VBox1);
    //tout afficher dans la fenetre
    exw ->show_all();
}
//constructeur / destructeur de la classe Dessin
Dessin::Dessin() {set_size_request(800, 900);} Dessin::~Dessin() {}
/********************************************************************************************************************/
/** Cette fonction dessine des cercles pour representer les pts attribués par l'utilisateur
 * @param cr: parametre de la librairie cairo
 * @return bool */
bool Dessin::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{

        Gtk::Allocation allocation = get_allocation(); 
        const int width = allocation.get_width();       //recup largeur
	    const int height = allocation.get_height();     //recup hauteur
        Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("Vampire_Page1.png");       //creer l'objet image à partir du fichier

        Gdk::Cairo::set_source_pixbuf(cr, image, 80, 50);
        cr->rectangle(80, 50, image->get_width(), image->get_height());
        cr->fill();
        cr->save();
        cr->set_source_rgb(1.0, 0.0, 0.0); //couleur : rouge
	    cr->set_line_width(10);
        //Conditions : chaque attributs , abilities, advantages.. etc doit etre placer dans l'endroit qui lui corresponds dans le fichier        
        if (name == "--Lasombra")
        {
	    cr->arc(image -> get_width()/2.792,image->get_height()/2.459, 1.0, 0.0,1*M_PI);
        }
    
        if (phy == "--Dexterity")
        {
            int s=10;
            for (int i=0; i< sum_physical1; i++)
            {
                cr->arc(210+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }

        }
        if (phy2 == "--Dexterity") 
        {
            int s=10;
            for (int i=0; i< sum_physical2; i++)
            {
                cr->arc(210+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (phy == "--Stamina") 
        {
            int s=10;
            for (int i=0; i< sum_physical1; i++)
            {
                cr->arc(210+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }

        }
        if (phy2 == "--Stamina") 
        {
            int s=10;
            for (int i=0; i< sum_physical2; i++)
            {
                cr->arc(210+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }

        }
        if (phy == "--Strength") 
        {
            int s=10;
            for (int i=0; i< sum_physical1; i++)
            {
                cr->arc(210+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }

        }
        if (phy2 == "--Strength") 
        {
            int s=10;
            for (int i=0; i< sum_physical2; i++)
            {
                cr->arc(210+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (ment == "--Perception") 
        {
            int s=10;
            for (int i=0; i< sum_mental; i++)
            {
                cr->arc(550+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (ment == "--Intelligence") 
        {
            int s=10;
            for (int i=0; i< sum_mental; i++)
            {
                cr->arc(550+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (ment == "--Wits") 
        {
            int s=10;
            for (int i=0; i< sum_mental; i++)
            {
                cr->arc(550+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social1 == "--Charisma") 
        {
            int s=10;
            for (int i=0; i< sum_social1; i++)
            {
                cr->arc(390+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social1 == "--Manipulation") 
        {
            int s=10;
            for (int i=0; i< sum_social1; i++)
            {
                cr->arc(390+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social1 == "--Appearance") 
        {
            int s=10;
            for (int i=0; i< sum_social1; i++)
            {
                cr->arc(390+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }

        if (social23 == "--Charisma") 
        {
            int s=10;
            for (int i=0; i< sum_social2; i++)
            {
                cr->arc(390+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social23 == "--Manipulation") 
        {
            int s=10;
            for (int i=0; i< sum_social2; i++)
            {
                cr->arc(390+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social23 == "--Appearance") 
        {
            int s=10;
            for (int i=0; i< sum_social2; i++)
            {
                cr->arc(390+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social33 == "--Charisma") 
        {
            int s=10;
            for (int i=0; i< sum_social3; i++)
            {
                cr->arc(390+s*i, 240, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social33 == "--Manipulation") 
        {
            int s=10;
            for (int i=0; i< sum_social2; i++)
            {
                cr->arc(390+s*i, 250, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (social33 == "--Appearance") 
        {
            int s=10;
            for (int i=0; i< sum_social3; i++)
            {
                cr->arc(390+s*i, 260, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (Skills == "--Animal Ken") 
        {
            int s=10;
            for (int i=0; i< sum_skills; i++)
            {
                cr->arc(390+s*i, 320, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (Skills == "--Crafts") 
        {
            int s=10;
            for (int i=0; i< sum_skills; i++)
            {
                cr->arc(390+s*i, 330, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (Skills == "--Drive") 
        {
            int s=10;
            for (int i=0; i< sum_skills; i++)
            {
                cr->arc(390+s*i, 330, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (Skills == "--Etiquette") 
        {
            int s=10;
            for (int i=0; i< sum_skills; i++)
            {
                cr->arc(390+s*i, 340, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Academics") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 320, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Computer") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 330, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Finance") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 340, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Investigation") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 350, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Law") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 365, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Medicine") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 380, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Occult") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 390, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Politics") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 410, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (know == "--Science") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 420, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
       if (know == "--Technology") 
        {
            int s=10;
            for (int i=0; i< sum_knowledges; i++)
            {
                cr->arc(550+s*i, 430, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Alertness") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 325, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Athletics") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 325, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Awareness") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 345, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Brawl") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 355, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Empathy") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 370, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Expression") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 380, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Intimidation") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 390, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Leadership") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 410, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Streetwise") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 420, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent11 == "--Subterfuge") 
        {
            int s=10;
            for (int i=0; i< sum_talent1; i++)
            {
                cr->arc(200+s*i, 430, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Alertness") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 325, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Athletics") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 325, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Awareness") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 345, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Brawl") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 355, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }

        if (talent22 == "--Empathy") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 370, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Expression") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 380, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Intimidation") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 390, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Leadership") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 410, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Streetwise") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 420, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
        if (talent22 == "--Subterfuge") 
        {
            int s=10;
            for (int i=0; i< sum_talent2; i++)
            {
                cr->arc(200+s*i, 430, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        }
            for (int i=0; i< sum_disciplines; i++)
            {
                int s=10;
                cr->arc(320+s*i, 990, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
            for (int i=0; i< sum_backgrounds; i++)
            {
                int s=10;
                cr->arc(700+s*i, 990, 1.0, 0.0, 2*M_PI);
                cr->fill_preserve();
                cr->stroke();   // outline it
            }
        draw_text(cr, 400, 300, name);      //remplir le nom
        draw_text(cr, 285, 990, dis);       //remplir la discipline 
        draw_text(cr, 650, 990, back);      //remplir background
    return true;
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies dans la 1ere page
* @param cr : parms de la librairie cairo
* @param rectangle_width : largeur 
* @param rectangle_height : hauteur 
* @param parms: le parametre à remplir en string
* @return RIEN */
void Dessin::draw_text(const Cairo::RefPtr<Cairo::Context>& cr,
                       int rectangle_width, int rectangle_height, string parms)
{
  Pango::FontDescription font;      //utilisateur de pango specialisé dans text
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  auto layout = create_pango_layout(parms);
  layout->set_font_description(font);
  int text_width;
  int text_height;
  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);
  cr->set_source_rgb(1.0, 0.0, 0.0);
  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);
  layout->show_in_cairo_context(cr);
}
/************************************************************************************
*******************************************************************************************/
//constructeur - destructeur 
Page2::Page2() {set_size_request(800, 900);} Page2::~Page2() {}
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* @param rectangle_width : largeur 
* @param rectangle_height : hauteur 
* @param parms: le parametre à remplir en string
* @return RIEN */
void Page2::draw_text(const Cairo::RefPtr<Cairo::Context>& cr,
                       int rectangle_width, int rectangle_height, string parms)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  auto layout = create_pango_layout(parms);
  layout->set_font_description(font);
  int text_width;
  int text_height;
  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);
  cr->set_source_rgb(1.0, 0.0, 0.0);
  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);
  layout->show_in_cairo_context(cr);
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* @return bool */
bool Page2::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
        Gtk::Allocation allocation = get_allocation(); 
        const int width = allocation.get_width();
	    const int height = allocation.get_height();
        Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("Vampire_Page2.png");
        Gdk::Cairo::set_source_pixbuf(cr, image, 80, 50);
        cr->rectangle(80, 50, image->get_width(), image->get_height());
        cr->fill();
        draw_text(cr, 450, 330, MF_socia);      //remplir avc Merits and flows social
        draw_text(cr, 450, 350, MF_socia2);     //remplir avc Merits and flows social
        draw_text(cr, 450, 400, MF_phy);        //remplir avc Merits and flows physique
        draw_text(cr, 450, 420, MF_phy2);       //remplir avc Merits and flows physique
        draw_text(cr, 950, 330, MF_ment);       //remplir avc Merits and flows mental
        draw_text(cr, 950, 350, MF_ment2);      //remplir avc Merits and flows mental
        draw_text(cr, 950, 400, SuperN);            //remplir avc Merits and flows supernatural
        draw_text(cr, 950, 420, SuperN2);           //remplir avc Merits and flows supernatural
        cr->save();
        return true;
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* width and height
* @return RIEN */
Page3::Page3() {set_size_request(800, 900);} Page3::~Page3() {}
void Page3::draw_text(const Cairo::RefPtr<Cairo::Context>& cr,
                       int rectangle_width, int rectangle_height, string parms)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  auto layout = create_pango_layout(parms);
  layout->set_font_description(font);
  int text_width;
  int text_height;
  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);
  cr->set_source_rgb(1.0, 0.0, 0.0);
  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);
  layout->show_in_cairo_context(cr);
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* width and height
* @return bool */
bool Page3::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
        Gtk::Allocation allocation = get_allocation(); 
        const int width = allocation.get_width();
	    const int height = allocation.get_height();
        Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("Vampire_Page3.png");
        Gdk::Cairo::set_source_pixbuf(cr, image, 80, 50);
        cr->rectangle(80, 50, image->get_width(), image->get_height());
        cr->fill();
        draw_text(cr, 400, 380, alies);
        cr->save();
        return true;
}
//constructeur - destructeur
Page4::Page4() {set_size_request(800, 900);} Page4::~Page4() {}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* @return bool */
bool Page4::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
      Pango::FontDescription font;
        Gtk::Allocation allocation = get_allocation(); 
        const int width = allocation.get_width();
	    const int height = allocation.get_height();
        Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("Vampire_Page4.png");
        Gdk::Cairo::set_source_pixbuf(cr, image, 80, 50);
        cr->rectangle(80, 50, image->get_width(), image->get_height());
        cr->fill();
        draw_text(cr, 400, 730, "205");
        draw_text(cr, 410, 755, "20");
        draw_text(cr, 450, 780, "20/12/1540");
        draw_text(cr, 420, 810, "Never");
        draw_text(cr, 420, 830, "Black");
        draw_text(cr, 420, 850, "Black");
        draw_text(cr, 420, 870, "Alian");
        draw_text(cr, 420, 895, "Earth");
        draw_text(cr, 420, 920, "175");
        draw_text(cr, 420, 940, "70 kg");
        draw_text(cr, 420, 960, "Male");
        cr->save();
    return true;
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction remplie avc du text les informatiosn choisies 
* @param cr : parms de la librairie cairo
* width and height
* @return RIEN */
void Page4::draw_text(const Cairo::RefPtr<Cairo::Context>& cr,
                       int rectangle_width, int rectangle_height, string parms)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  auto layout = create_pango_layout(parms);
  layout->set_font_description(font);
  int text_width;
  int text_height;
  //get the text dimensions (it updates the variables -- by reference)
  layout->get_pixel_size(text_width, text_height);
  cr->set_source_rgb(1.0, 0.0, 0.0);
  // Position the text in the middle
  cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);
  layout->show_in_cairo_context(cr);
}
/************************************************************************************
*******************************************************************************************/
/** Cette fonction  donne la possibilité à l'utilisateur d'exporter son formulaire au format pdf
* @param cr : parms de la librairie cairo
* @return bool */
void ExampleWindow:: export_to_pdf()
{
    Glib::RefPtr<Gtk::PrintOperation> op = Gtk::PrintOperation::create();
    op->set_export_filename("test.pdf");
    Gtk::PrintOperationResult res = op->run(Gtk::PRINT_OPERATION_ACTION_EXPORT);
}