(defun my-equal (l1 l2)
	(cond
		((eq l1 l2) t)
		((and (consp l1)(consp l2))
			(and (my-equal (car l1)(car l2))
				(my-equal(cdr l1)(cdr l2)))
				(t nil)
	)
))
