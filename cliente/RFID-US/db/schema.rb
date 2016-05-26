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

ActiveRecord::Schema.define(version: 20140730102130) do

  # These are extensions that must be enabled in order to support this database
  enable_extension "plpgsql"

  create_table "a_deviceconfiguration", primary_key: "ad_id", force: true do |t|
    t.text    "ad_ipdispositivo"
    t.text    "ad_numserie"
    t.integer "ad_tipocliente"
    t.integer "ad_refreshtime",   default: 0, null: false
  end

  create_table "a_serverconfiguration", primary_key: "a_id", force: true do |t|
    t.text "a_url"
  end

  create_table "a_serverconfigurations", force: true do |t|
    t.inet     "ipdevice"
    t.inet     "networkmask"
    t.inet     "gateway"
    t.text     "url_server"
    t.integer  "refreshtime"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "configurations", force: true do |t|
    t.inet     "ipdevice"
    t.inet     "networkmask"
    t.inet     "gateway"
    t.text     "url_server"
    t.integer  "refreshtime"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  create_table "d_auladispositivo", primary_key: "da_id", force: true do |t|
    t.integer "da_idaula"
    t.integer "da_iddispositivo"
  end

  add_index "d_auladispositivo", ["da_idaula"], name: "fki_aulas_idaula", using: :btree
  add_index "d_auladispositivo", ["da_iddispositivo"], name: "fki_aula_dispositivoid", using: :btree

  create_table "d_aulas", primary_key: "d_id", force: true do |t|
    t.text "d_tipoaula"
    t.text "d_aula"
    t.text "d_edificio"
  end

  create_table "l_logregistros", primary_key: "l_id", force: true do |t|
    t.integer  "l_idusuario"
    t.datetime "l_datetime"
  end

  create_table "u_users", primary_key: "u_id", force: true do |t|
    t.text "u_documento"
    t.text "u_nombre"
    t.text "u_registro"
  end

  create_table "users", force: true do |t|
    t.string   "email",                  default: "", null: false
    t.string   "encrypted_password",     default: "", null: false
    t.string   "reset_password_token"
    t.datetime "reset_password_sent_at"
    t.datetime "remember_created_at"
    t.integer  "sign_in_count",          default: 0,  null: false
    t.datetime "current_sign_in_at"
    t.datetime "last_sign_in_at"
    t.string   "current_sign_in_ip"
    t.string   "last_sign_in_ip"
    t.datetime "created_at"
    t.datetime "updated_at"
  end

  add_index "users", ["email"], name: "index_users_on_email", unique: true, using: :btree
  add_index "users", ["reset_password_token"], name: "index_users_on_reset_password_token", unique: true, using: :btree

end
