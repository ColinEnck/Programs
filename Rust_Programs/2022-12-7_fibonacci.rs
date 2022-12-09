use std::io;

fn main() {
    println!("How many numbers?");
    let mut limit = String::new();
    io::stdin().read_line(&mut limit).expect("Failed to read line");
    let limit: u64 = limit.trim().parse().expect("Not a number");

    let num: u64 = 1;
    let prev_num: u64 = 0;
    let counter: u64 = 0;
    fibonacci(num, prev_num, counter, limit);
}

fn fibonacci(mut num: u64, mut prev_num: u64,
    mut counter: u64, limit: u64){
    println!("{num}");
    let temp = prev_num;
    prev_num = num;
    num += temp;
    counter += 1;
    if counter < limit {
        fibonacci(num, prev_num, counter, limit);
    } else { return; }
}