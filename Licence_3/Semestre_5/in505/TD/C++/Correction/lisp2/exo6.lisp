(defun rever (liste)
	(if (null liste)
		nil
		(append (rever (cdr liste)) (list (car liste)))
	)
)
; on concatene le premier elt à la fin de la liste
; taille d'une liste (list-length liste)

;(cons elt lst) => liste normale
;(cons lst elt) => liste imbriquée
;(cons arg1 arg2) => concatene, avec arg1 le car, arg2 le cdr
