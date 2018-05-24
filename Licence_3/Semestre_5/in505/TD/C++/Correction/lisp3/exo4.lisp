(defun interspace_it (obj liste)
	(let (res)
		(do ((tmp liste (cdr tmp)))
				((null (cdr tmp)) res (append res (list (car tmp))))
				(setf res (append res (list (car tmp)) (list obj)))
		)
	)
)

(defun interspace_rec (obj liste)
	(if (or (not (listp liste)) (null liste))
		nil
		(if (null (cdr liste))
			liste
			(cons (car liste) (cons obj (interspace_rec obj (cdr liste))))
		)
	)
)
