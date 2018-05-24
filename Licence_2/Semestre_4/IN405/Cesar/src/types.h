/**
 * \file types.h
 * \author Clément Caumes 21501810
 * \date 30 avril 2017
 * \brief contient les constantes utilisées dans le projet
 */

#ifndef __TYPES_H
#define __TYPES_H

/** MODES utilisateur, groupe, autres, accès autorisé en lecture, écriture et exécution */
#define MODES S_IRWXU|S_IRWXG|S_IRWXO

/** FLAGS création en écriture d'un fichier */
#define FLAGS O_WRONLY|O_CREAT|O_TRUNC

#endif
