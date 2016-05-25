# encoding: UTF-8
# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended that you check this file into your version control system.

ActiveRecord::Schema.define(version: 20160331063253) do

  # These are extensions that must be enabled in order to support this database
  enable_extension "plpgsql"

  create_table "cards", force: :cascade do |t|
    t.text     "codigo"
    t.integer  "usuario_id"
    t.integer  "activa"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
  end

  add_index "cards", ["usuario_id"], name: "index_cards_on_usuario_id", using: :btree

  create_table "emails", force: :cascade do |t|
    t.text     "email"
    t.text     "password"
    t.text     "smtp_server"
    t.integer  "puerto"
    t.boolean  "ssl"
    t.datetime "created_at",  null: false
    t.datetime "updated_at",  null: false
  end

  create_table "equipos", force: :cascade do |t|
    t.text     "nombre"
    t.text     "zona"
    t.text     "ip"
    t.integer  "activo"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
    t.text     "dns"
  end

  create_table "logs", force: :cascade do |t|
    t.datetime "tiempo_lectora"
    t.datetime "tiempo_registro"
    t.integer  "equipo_id"
    t.integer  "card_id"
    t.integer  "usuario_id"
    t.datetime "created_at",      null: false
    t.datetime "updated_at",      null: false
    t.boolean  "entrada"
  end

  add_index "logs", ["card_id"], name: "index_logs_on_card_id", using: :btree
  add_index "logs", ["equipo_id"], name: "index_logs_on_equipo_id", using: :btree
  add_index "logs", ["usuario_id"], name: "index_logs_on_usuario_id", using: :btree

  create_table "users", force: :cascade do |t|
    t.string   "email",                  default: "", null: false
    t.string   "encrypted_password",     default: "", null: false
    t.string   "reset_password_token"
    t.datetime "reset_password_sent_at"
    t.datetime "remember_created_at"
    t.integer  "sign_in_count",          default: 0,  null: false
    t.datetime "current_sign_in_at"
    t.datetime "last_sign_in_at"
    t.inet     "current_sign_in_ip"
    t.inet     "last_sign_in_ip"
    t.datetime "created_at",                          null: false
    t.datetime "updated_at",                          null: false
    t.integer  "admin"
  end

  add_index "users", ["email"], name: "index_users_on_email", unique: true, using: :btree
  add_index "users", ["reset_password_token"], name: "index_users_on_reset_password_token", unique: true, using: :btree

  create_table "usuarios", force: :cascade do |t|
    t.text     "codigo"
    t.text     "nombre"
    t.text     "apellidos"
    t.text     "dni"
    t.text     "domicilio"
    t.text     "email"
    t.integer  "centro"
    t.integer  "dentro"
    t.integer  "activo"
    t.datetime "created_at", null: false
    t.datetime "updated_at", null: false
    t.integer  "card_id"
  end

  add_foreign_key "cards", "usuarios"
  add_foreign_key "logs", "cards"
  add_foreign_key "logs", "equipos"
  add_foreign_key "logs", "usuarios"
  add_foreign_key "usuarios", "cards"
end
