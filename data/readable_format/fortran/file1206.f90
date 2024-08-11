program t
    type x
        integer::i=1
    end type x
    type(x)::y
    print '(i0)',y%i
end program t