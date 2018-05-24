(defun test-list (liste)
	(cond
		((listp(car liste)) t)
		((null liste) nil)
		(t (test-list (cdr liste)))
	)
)

