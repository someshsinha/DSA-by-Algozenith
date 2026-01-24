/*
question => find the different possible subsequences of the given string
abaac=>

a     b     a    a      c

'a'   'b'  'ba'  'baa'  'baac'
      'ab' 'aba' 'abaa' 'abaac'
                        'c'
                        'baac'
                        'abaac'
                        'bac'
                        'abac'
                        'bc'
                        'abc'

logic => is this alphabet occuring for the first time??
        => yes ---- number of subsequences = number of subsequences which was formed in it's previous block
        => no  ---- number of subsequences that has ever been formed before it + 1
*/
