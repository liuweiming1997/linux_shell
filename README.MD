# just save my homework

## style glide

### can not
* shell `var` **can not** use space to split them, it`s means
	* `var = 2` is wrong
	* `var=2` is correct

* shell `let` **can not** use space to split them, it`s means
	* `let a = 2 + 2` is wrong
	* `let a=2+2` is correct

### must
* shell `test` **must** use space to split them, it`s means
	* `test $a=$b` is wrong, because now the "=" will means assignment
	* `test $a = $b` is correct

* shell `expr` **must** use space to split, it`s means
	* `expr 2+1` is wrong
	* `expr 2 + 1` is correct

* shell `if` **must** use space to split, it`s means
	* `if [$var lt 1]` is wrong
	* `if [ $var lt 1 ]` is correct