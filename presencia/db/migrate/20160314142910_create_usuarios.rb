class CreateUsuarios < ActiveRecord::Migration
  def change
begin
    create_table :usuarios do |t|
      t.text :codigo
      t.text :nombre
      t.text :apellidos
      t.text :dni
      t.text :domicilio
      t.text :email
      t.integer :centro
      t.references :tarjeta, index: true, foreign_key: true
      t.integer :dentro
      t.integer :activo
      t.timestamps null: false
    end
end

  add_column :usuarios, :card_id, :integer
  add_foreign_key :usuarios, :cards
  end
end
