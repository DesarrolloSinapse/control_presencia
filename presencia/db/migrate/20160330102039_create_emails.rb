class CreateEmails < ActiveRecord::Migration
  def change
    create_table :emails do |t|
      t.text :email
      t.text :password
      t.text :smtp_server
      t.integer :puerto
      t.boolean :ssl

      t.timestamps null: false
    end
  end
end
