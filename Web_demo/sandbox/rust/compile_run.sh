set -e

mv /app/script.rs /app/main.rs

echo '[package]
name = "myapp"
version = "0.1.0"
edition = "2018"

[[bin]]
name = "test"
path = "main.rs"' > /app/Cargo.toml

cd /app

cargo build --release

./target/release/test

