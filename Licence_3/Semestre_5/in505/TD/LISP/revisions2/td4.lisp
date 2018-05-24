(defun compte-arg (&optional l &rest liste)
	(cond 
		((null l) 0)
		((null liste) 1)
		(t
			(+ 1 (apply 'compte-arg liste))
		)
	)
)
