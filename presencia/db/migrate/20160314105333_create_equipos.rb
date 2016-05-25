class CreateEquipos < ActiveRecord::Migration
  def change
    create_table :equipos do |t|
      t.text :nombre
      t.text :zona
      t.text :ip
      t.integer :activo

      t.timestamps null: false
    end
  end
end
