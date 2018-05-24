(defun snoc (liste)
	(cond
		((null liste) (format nil "()"))
		((atom liste) (format nil "~A" liste))
		((null (cdr liste)) (format nil "(cons ~A ())" (snoc (car liste))))
		(t
			(format nil "(cons ~A ~A)" (snoc (car liste))(snoc (cdr liste)))
		)
	)
)

(defun aplanir (liste)
	(cond
		((null liste) nil)
		((atom liste) (cons liste nil))
		(t (append (aplanir (car liste))(aplanir (cdr liste))))
	)
)
