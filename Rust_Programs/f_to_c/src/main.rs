use std::io;

fn main() {
    println!("Degrees in Fahrenheit: ");

    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    let input: f64 = input.trim().parse().expect("Not a number");

    let celcius_deg = (input - 32.0) * (5.0/9.0);

    println!("Degrees in Celcius: {celcius_deg}");
}
