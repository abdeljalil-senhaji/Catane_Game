# Vampire Game

In Vampire, players assume the personas of vampires — the immortal bloodsuckers of the horror genre — and guide these characters through a world virtually identical to our own. But these aren’t quite the vam- pires you might know from Dracula or Twilight. The vampires that exist now — or Kindred, or Cainites, as they commonly call themselves — are both similar to and different from what we might expect. In many ways, vampires resemble the familiar monsters of myth,cinema, folklore, and fiction. However — as many an intrepid vampire-hunter has learned to his sorrow — not all of the stories about vampires are true.


# Installation

Before the installation, make sure you have C++ 2011 version and Gtkmm 3.0.


`https://gitlab.com/....`

`cd catane_app`

To get started, write in the console the following command:

`make clean; make; ./abdel;`


# How to play

- Choose Mental, Social and Physical attributes, You have 15 points to give to the three attributes, but you have to respect the repartition 7/5/3. For example, you can give 7 points to the physical attributes, 5 to social and 3 to mental.

- Choose the abilites: the skills, talents and knowledges. You have 27 points to attribute to each categorie, make sure you respect the repartition 13/9/5, if you don't, a pop-up window will display to remember you of the rules.

- Choose the advantages: disciplines, backgrounds and virtues, here you must respect the imposed repartition, 7 points to virtues, 3 to disciplines and 5 to backgrounds.

- Choose merits and flows.

- Push `Valider personnage` button, if everything goes well, a pop-up window will display to inform you that your information has been saved.

- Push `Afficher les formulaires` button, the 4 pages filled with information you gave will display. The information you selected is written in red and the points you attributed are also red.

Please, see this following example:

![Example](Tutorial.gif)


# Code

The interface was developed in oriented-object format, each window is a class. Each class contains methods for points attribution and texts/drawings on the formulaires.


