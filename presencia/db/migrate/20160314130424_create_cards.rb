class CreateCards < ActiveRecord::Migration
  def change
    create_table :cards do |t|
      t.text :codigo
      t.references :usuario, index: true, foreign_key: true
      t.integer :activa

      t.timestamps null: false
    end
  end
end
