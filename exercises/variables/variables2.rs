// variables2.rs
//
// Execute `rustlings hint variables2` or use the `hint` watch subcommand for a
// hint.


fn main() {
    let x=10;
    //we cannot use uninitialized variable at first we have to initialized first before printing
    //this leads to undefined behaviour
    if x == 10 {
        println!("x is ten!");
    } else {
        println!("x is not ten!");
    }
}
