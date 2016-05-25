class AddColumnDnsToEquipos < ActiveRecord::Migration
  def change
  	add_column :equipos, :dns, :text
  end
end
