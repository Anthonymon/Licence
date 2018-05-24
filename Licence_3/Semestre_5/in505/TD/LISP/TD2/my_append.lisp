(defun my-append(liste1 liste2)
	(if(null liste1) liste2
		(my-append (list liste1 (car liste2)) (cdr liste2))
		(cons (car liste1) (my-append(cdr liste1) liste2))
	)
)

