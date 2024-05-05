import pg from "pg";
const { Pool } = pg;

const pool = new Pool({
    user: "postgres",
    password: "password",
    host: "db",
    database: "notes_app_db",
    port: 5432,
    max: 5
})

export default pool