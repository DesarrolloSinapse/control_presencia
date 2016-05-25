class CreateLogs < ActiveRecord::Migration
  def change
    create_table :logs do |t|
      t.datetime :tiempo_lectora
      t.datetime :tiempo_registro
      t.references :equipo, index: true, foreign_key: true
      t.references :card, index: true, foreign_key: true
      t.references :usuario, index: true, foreign_key: true

      t.timestamps null: false
    end
  end
end
