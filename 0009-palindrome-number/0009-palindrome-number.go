func isPalindrome(x int) bool {
    rev :=0
    temp := x
    for x>0{
        rem := x%10
        rev = rev*10 + rem
        x = x/10
    }
    return temp == rev
}