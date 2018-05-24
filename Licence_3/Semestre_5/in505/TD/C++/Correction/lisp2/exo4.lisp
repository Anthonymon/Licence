(defun min-max (liste)
	(if (or (not (listp liste)) (null liste)) ; si ce n'est pas une liste ou si c'est liste vide
		NIL
		(let ((min (car liste)) (max (car liste)) (queue (cdr liste)))
			(dolist (tmp queue)
				(if (> tmp max) (setf max tmp))
				(if (< tmp min) (setf min tmp))
			)
			(format t "min: ~A max: ~A" min max)
		)
	)
)
