(defun maxi-setf (arg)
	(cond 
		((not(boundp 'maxi)) (setf maxi arg))
		((< maxi arg)(setf maxi arg))
		(t maxi)
	)
)
